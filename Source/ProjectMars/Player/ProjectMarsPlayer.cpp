// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMarsPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/Controllers/AIControllerBase.h"
#include "ProjectMars/Factions/FactionBase.h"
#include "ProjectMars/Framework/MarsGameStateBase.h"
#include "ProjectMars/UI/BaseHUD.h"
#include "DrawDebugHelpers.h"
#include "ProjectMars/UI/Widgets/WidgetComponents/ArmyWidgetComponent.h"
#include "ProjectMars/TimeManagement/TimeManagementComponent.h"
#include "ProjectMars/Components/PlayerManagement/PlayerManagerComponent.h"
#include "ProjectMars/Delegates/DelegateController.h"
#include "ProjectMars/Economy/EconomyController.h"
#include "ProjectMars/Military/Army.h"
#include "ProjectMars/Nation/State.h"


// Sets default values
AProjectMarsPlayer::AProjectMarsPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Scene Component/Root Component
	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	RootComponent = RootComp;

	// Spring Arm
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComp->SetupAttachment(RootComp);
	SpringArmComp->bEnableCameraLag = true;

	// Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArmComp);

	// Economy Manager
	State = NewObject<UState>();
	EconomyController = State->GetEconomyController();
	
	MovementSpeed = 500.f;

	bHasChosenFaction = false;
	bHasSetTreasury = false;

	MonthIndex = 1;
}

EFactionName AProjectMarsPlayer::GetFactionName() const
{
	return FactionName;
}

void AProjectMarsPlayer::SetFactionName(const EFactionName& FacName)
{
	FactionName = FacName;
}

// Called when the game starts or when spawned
void AProjectMarsPlayer::BeginPlay()
{
	Super::BeginPlay();

	InitialiseGameStateRefs();
	InitialisePlayerController();
	InitialisePlayerNation();

	/*UGameplayStatics::OpenLevel(GetWorld(), "ChooseFaction");
	CurrentLevel = GetWorld()->GetMapName();*/

	MarsGameStateBase->AddPlayerToPlayerArray(this);
}

// Called every frame
void AProjectMarsPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PawnMovement(DeltaTime);

	// TODO: Might be better to find some way of this not being in tick
	SetArmyClickedOn();
	if(FactionArmy)
	{
		FVector MeshLoc = FactionArmy->GetActorLocation();
		MeshLoc.Z += (FactionArmy->Mesh->Bounds.BoxExtent.Z / 2);
		
		FVector MeshExtent = FVector(FactionArmy->Mesh->Bounds.BoxExtent);
		MeshExtent.X += 2.f;
		MeshExtent.Y += 2.f;
		
		DrawDebugBox(GetWorld(), MeshLoc, MeshExtent, FColor::Green, false, -1.f, 0, 2.f);
	}
}

void AProjectMarsPlayer::InitialiseGameStateRefs()
{
	MarsGameStateBase = Cast<AMarsGameStateBase>(GetWorld()->GetGameState());
	ensure(MarsGameStateBase);

	if (!MarsGameStateBase) return;
	MarsGameStateBase->AddPlayerToPlayerArray(this);

	DelegateController = MarsGameStateBase->GetDelegateController();
	ensure(DelegateController);
		
	// TODO: BUG: If I uncomment this out, I can control the game time. However, if we run this code when not controlled by player I cannot.
	if (!IsPlayerControlled()) return;
	UE_LOG(LogTemp, Warning, TEXT("Player is controlled!"));
		
	MarsGameStateBase->InitialiseReferences(this);

	// TODO: Test code to be removed - The player will get their state from the list created by the Game State
	UState* PlayersState = NewObject<UState>();
	PlayersState->SubscribeToDelegateEvents(DelegateController);
	State = PlayersState;

	// Tells all listeners that it is safe to initialise Player ptrs from AMarsGameStateBase class
	DelegateController->OnPlayerInitialisation.Broadcast();
}

void AProjectMarsPlayer::InitialisePlayerController()
{
	if (IsPlayerControlled())
	{
		BasePlayerController = Cast<ABasePlayerController>(GetController());;

		if (BasePlayerController)
		{
			BaseHUD = Cast<ABaseHUD>(BasePlayerController->GetHUD());
			BasePlayerController->OnRMBPressed.AddDynamic(this, &AProjectMarsPlayer::IssueMoveArmyOrder);
			if (BaseHUD)
			{
				BaseHUD->InitialiseEconomyData(State->GetEconomyController()->GetEconomyData());
			}
		}
		else if (!BasePlayerController)
		{
			UE_LOG(LogTemp, Error, TEXT("BasePlayerController is nullptr - AProjectMarsPlayer::BeginPlay"));
		}
	}
}

void AProjectMarsPlayer::PawnMovement(float DeltaTime)
{
	if(!MovementDirection.IsZero())
	{
		const FVector NewLocation = GetActorLocation() + (MovementDirection * DeltaTime * MovementSpeed);
		SetActorLocation(NewLocation);
	}
}

// Is called by the GameState class
void AProjectMarsPlayer::UpdatePlayerFactionInfo() const
{	
	
}

void AProjectMarsPlayer::MoveForward(float Val)
{
	// The FMath::Clamp helps to prevent higher speeds when pressing two keyboard keys at once
	MovementDirection.X = FMath::Clamp(Val, -1.f, 1.f);
}

void AProjectMarsPlayer::MoveRight(float Val)
{
	// The FMath::Clamp helps to prevent higher speeds when pressing two keyboard keys at once
	MovementDirection.Y = FMath::Clamp(Val, -1.f, 1.f);
}

// Testing the functionality of choosing the faction from a TMap of faction objects - see AProjectMarsPlayer::CreateArrayOfAvailableFactions()
void AProjectMarsPlayer::ChooseRome()
{
	if(bHasChosenFaction) return;
	UPlayerManagerComponent* const PlayerManagerComponent = MarsGameStateBase->GetPlayerManagerComponent();

	int32 Index = PlayerManagerComponent->GetAllFactionsArray().Find(EFactionName::Rome);
	FactionName = PlayerManagerComponent->GetAllFactionsArray()[Index];
	PlayerManagerComponent->GetAvailableFactionsArray().Remove(EFactionName::Rome);
	UE_LOG(LogTemp, Warning, TEXT("Player Faction: ROME"));

	PlayerManagerComponent->AssignAIFactions();
	bHasChosenFaction = true;
}

void AProjectMarsPlayer::ChooseEtruria()
{
	return; 
}

void AProjectMarsPlayer::ChooseCarthage()
{
	return;
}

void AProjectMarsPlayer::InitialisePlayerFaction(const EFactionName& Faction)
{
	if(PlayerFaction && MarsGameStateBase)
	{
		UE_LOG(LogTemp, Warning, TEXT("Faction Name: %s"), *PlayerFaction->FactionName.ToString());
		InitialiseHUD();

		bHasChosenFaction = true;
		MarsGameStateBase->GetTimeManagementComponent()->SetLastUpdateCheckTime(FPlatformTime::Seconds());
	}
	if(!PlayerFaction)
	{
		//UE_LOG(LogTemp, Error, TEXT("PlayerFaction is NULL!"))
	}
}

void AProjectMarsPlayer::InitialiseHUD()
{
	if(BaseHUD)
	{
		BaseHUD->InitialiseFactionBase(PlayerFaction);
	}
	if(!BaseHUD)
	{
		UE_LOG(LogTemp, Error, TEXT("BaseHUD is nullptr - AProjectMarsPlayer::InitialiseHUD"));
	}
}

// TODO: Implement natural system of updating various revenue streams
void AProjectMarsPlayer::UpdatePlayerIncome()
{
	if (PlayerFaction)
	{
		UE_LOG(LogTemp, Log, TEXT("Updating player income"));
	}
}

// TODO: May want to refactor this so that it is implemented a little cleaner.
void AProjectMarsPlayer::UpdateGameSpeed(float Val)
{
	if(Val == 0) return;
	if(!MarsGameStateBase) return;
	
	if(Val == 1)
	{
		MarsGameStateBase->GetTimeManagementComponent()->SetUpdateCheckFrequency(5.0f);
		GameSpeed = 1;
	}
	if(Val == 2)
	{
		MarsGameStateBase->GetTimeManagementComponent()->SetUpdateCheckFrequency(3.0f);
		GameSpeed = 2;
	}
	if(Val == 5)
	{
		MarsGameStateBase->GetTimeManagementComponent()->SetUpdateCheckFrequency(1.0f);
		GameSpeed = 5;
	}
}

void AProjectMarsPlayer::UpdatePlayerPopulationData()
{
	if(PlayerFaction)
	{
		FPopulation& Pop = PlayerFaction->Population;
		Pop.UpdateMonthlyPopulation();
	}
}

void AProjectMarsPlayer::InitialisePlayerNation()
{
	State = MarsGameStateBase->GetStateForPlayer("Rome");
}

void AProjectMarsPlayer::SetArmyClickedOn()
{
	if (!BasePlayerController) return;
	if (!BasePlayerController->IsInputKeyDown(EKeys::LeftMouseButton)) return;
	
	FHitResult LeftClick;
	if(BasePlayerController->GetHitResultUnderCursor(ECC_Visibility, false, LeftClick))
	{
		if(LeftClick.GetActor())
		{
			FactionArmy = Cast<AArmy>(LeftClick.GetActor());
			if(FactionArmy && ClickCounter == 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("FactionArmy selected"));
				FactionArmy->OwnerOfArmy = this;
				TempArmyPtr = FactionArmy;
				// FactionArmy->ShowArmyWidget();
				FactionArmy->ArmyWidgetComponent->ArmyClicked(this);
				
				ClickCounter = 1;
			}
			else if (!FactionArmy && ClickCounter == 1)
			{
				UE_LOG(LogTemp, Error, TEXT("No army selected"));
				FactionArmy = nullptr;;

				if(TempArmyPtr)
				{
					TempArmyPtr->ArmyWidgetComponent->ArmyUnClicked(this);
					// TempArmyPtr->HideArmyWidget();
				}
				
				ClickCounter = 0;
			}
		}
	}
	if(BaseHUD && BaseHUD->ArmySelected)
	{
		FactionArmy = BaseHUD->ArmySelected;
		if(FactionArmy)
		{

		}
		else
		{
			FactionArmy = nullptr;;
		}
	}
}

const AArmy* AProjectMarsPlayer::GetArmyClickedOn()
{
	return FactionArmy;
}

void AProjectMarsPlayer::IssueMoveArmyOrder()
{
	if (!BasePlayerController) return;
	if (!FactionArmy) return;
		
	FHitResult RightClickLoc;
	if(BasePlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, RightClickLoc))
	{
		// TODO: Need to change this so that we can only right click on appropriate actors such as terrain, or cities, or other armies etc.
		if(RightClickLoc.GetActor())
		{
			FactionArmy->TargetLocation = FVector(RightClickLoc.ImpactPoint.X, RightClickLoc.ImpactPoint.Y, RightClickLoc.GetActor()->GetActorLocation().Z);
			FactionArmy->SetPlayerOwnerOfArmy(this);
			
			DrawDebugBox(GetWorld(), RightClickLoc.ImpactPoint, FVector(25.f, 25.f, 25.f), FColor::Yellow, false, 4.f, 0, 2.f);
		}
	}
}

void AProjectMarsPlayer::SetTimeManagementPointers(AProjectMarsPlayer* Player)
{
	if(!MarsGameStateBase) return;
}

// Called to bind functionality to input
void AProjectMarsPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent)
	{
		// Movement
		PlayerInputComponent->BindAxis("MoveForward", this, &AProjectMarsPlayer::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &AProjectMarsPlayer::MoveRight);

		// Game Speed
		PlayerInputComponent->BindAxis("GameSpeed", this, &AProjectMarsPlayer::UpdateGameSpeed);
	}
}