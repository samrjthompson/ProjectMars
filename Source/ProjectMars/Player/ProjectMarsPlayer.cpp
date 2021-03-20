// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMarsPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/Controllers/AIControllerBase.h"
#include "ProjectMars/Factions/FactionBase.h"
#include "ProjectMars/Framework/MarsGameStateBase.h"
#include "ProjectMars/UI/BaseHUD.h"
#include "ProjectMars/Framework/TimeInGame.h"


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

	MovementSpeed = 500.f;

	bHasChosenFaction = false;
	bHasSetTreasury = false;

	MonthIndex = 1;

	// TIME
	FCampaignDateTime Obj;
	CampaignDateTimePtr = &Obj;
}

void AProjectMarsPlayer::InitialiseAIComponents(AProjectMarsPlayer* AIPlayer)
{
	if (!AIPlayer) { return; }
	
	AIPlayer->FactionEconomics = &AIPlayer->PlayerFaction->Economics;
}

// Called when the game starts or when spawned
void AProjectMarsPlayer::BeginPlay()
{
	Super::BeginPlay();

	InitialiseGameStateRefs();

	InitialisePlayerController();

	/*UGameplayStatics::OpenLevel(GetWorld(), "ChooseFaction");
	CurrentLevel = GetWorld()->GetMapName();*/
}

// Called every frame
void AProjectMarsPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PawnMovement(DeltaTime);
}

void AProjectMarsPlayer::InitialiseGameStateRefs()
{
	MarsGameStateBase = Cast<AMarsGameStateBase>(GetWorld()->GetGameState());

	if(MarsGameStateBase)
	{
		MarsGameStateBase->PlayerArray.Emplace(this);
		
		// TODO: BUG: If I uncomment this out, I can control the game time. However, if we run this code when not controlled by player I cannot.
		if (!IsPlayerControlled()) { return; }
		
		MarsGameStateBase->InitialiseReferences(this);
	}
	if(!MarsGameStateBase)
	{
		UE_LOG(LogTemp, Error, TEXT("MarsGameStateBase is NULL!"))
	}
}

void AProjectMarsPlayer::InitialisePlayerController()
{
	if (IsPlayerControlled())
	{
		BasePlayerController = Cast<ABasePlayerController>(GetController());;

		if (BasePlayerController)
		{
			BaseHUD = Cast<ABaseHUD>(BasePlayerController->GetHUD());
		}
		if (!BasePlayerController)
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

void AProjectMarsPlayer::SetTreasury()
{
	if(FactionEconomics)
	{
		PlayerEconomy.Treasury = FactionEconomics->Treasury;

		UE_LOG(LogTemp, Warning, TEXT("SetTreasury CALLED!"))
		
		bHasSetTreasury = true;
	}
	if(!FactionEconomics)
	{
		UE_LOG(LogTemp, Error, TEXT("FactionEconomics is NULL!"))
	}
}

// Is called by the GameState class
void AProjectMarsPlayer::UpdatePlayerFactionInfo()
{
	UpdatePlayerIncome();
	UpdatePlayerPopulationData();
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
	if(bHasChosenFaction) { return; }

	PlayerFaction = MarsGameStateBase->AvailableFactionsMap->Find(EFactionName::Rome);
	MarsGameStateBase->AvailableFactionsMap->Remove(EFactionName::Rome);

	InitialisePlayerFaction(EFactionName::Rome);

	MarsGameStateBase->AssignAIFactions();

	// OnFactionChosenByPlayer.Broadcast();
}

void AProjectMarsPlayer::ChooseEtruria()
{
	if(bHasChosenFaction) { return; }
	InitialisePlayerFaction(EFactionName::Etruria);

	// OnFactionChosenByPlayer.Broadcast();

	MarsGameStateBase->AssignAIFactions();
}

void AProjectMarsPlayer::ChooseCarthage()
{
	if(bHasChosenFaction) { return; }
	InitialisePlayerFaction(EFactionName::Carthage);

	// OnFactionChosenByPlayer.Broadcast();

	MarsGameStateBase->AssignAIFactions();
}

void AProjectMarsPlayer::InitialisePlayerFaction(const EFactionName& Faction)
{
	if(bHasChosenFaction) { return; }
	
	/*switch (Faction)
	{
	case EFactionName::Rome: PlayerFaction = &MarsGameStateBase->RomeFaction;
		break;

	case EFactionName::Etruria : PlayerFaction = &MarsGameStateBase->EtruriaFaction;
		break;

	case EFactionName::Carthage : PlayerFaction = &MarsGameStateBase->CarthageFaction;
		break;

	default: PlayerFaction = nullptr;
		break;
	}*/

	if(PlayerFaction && MarsGameStateBase)
	{
		UE_LOG(LogTemp, Warning, TEXT("Faction Name: %s"), *PlayerFaction->FactionName.ToString());
		InitialiseHUD();

		// This is a pointer to the address of the faction data object 
		// BaseFactionData = &PlayerFaction->GetRefToFactionData();

		// TODO: Move this to somewhere the AI can also be initialised
		FactionEconomics = &PlayerFaction->Economics;

		bHasChosenFaction = true;
		MarsGameStateBase->LastUpdateCheckTime = GetWorld()->GetTimeSeconds();
	}
	if(!PlayerFaction)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerFaction is NULL!"))
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
	if(PlayerFaction && !bHasSetTreasury)
	{
		SetTreasury();
	}
	if (PlayerFaction && bHasSetTreasury)
	{
		// AddMoney();

		FFactionEconomics& Obj = PlayerFaction->Economics;
		FPopulation& PopObj = PlayerFaction->FactionPop;
		
		Obj.CollectTaxes(PopObj);
		Obj.ApplyNetIncomeToTreasury();
		
		PlayerEconomy.Treasury = Obj.Treasury;

		// UE_LOG(LogTemp, Warning, TEXT("Faction Gross income: %f"), Obj.GrossIncome);
		// UE_LOG(LogTemp, Warning, TEXT("Faction Outgoings: %f"), Obj.GetTotalOutgoings());
		// UE_LOG(LogTemp, Warning, TEXT("Faction Net income: %f"), Obj.NetIncome);
	}
}

void AProjectMarsPlayer::AddMoney()
{
	if(FactionEconomics)
	{
		FactionEconomics->Treasury += 10.f;
		
		UE_LOG(LogTemp, Warning, TEXT("AddMoney CALLED!"))
	}
}

// TODO: May want to refactor this so that it is implemented a little cleaner.
void AProjectMarsPlayer::UpdateGameSpeed(float Val)
{
	if(Val == 0) { return; }
	if(!MarsGameStateBase) { return; }
	
	if(Val == 1)
	{
		MarsGameStateBase->UpdateCheckFrequency = 5.f;
	}
	if(Val == 2)
	{
		MarsGameStateBase->UpdateCheckFrequency = 3.f;
	}
	if(Val == 5)
	{
		MarsGameStateBase->UpdateCheckFrequency = 1.f;
	}	
}

void AProjectMarsPlayer::UpdatePlayerPopulationData()
{
	if(PlayerFaction)
	{
		FPopulation& Pop = PlayerFaction->FactionPop;
		Pop.UpdateMonthlyPopulation();
	}
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

		// Economy
		PlayerInputComponent->BindAction("Money", IE_Pressed, this, &AProjectMarsPlayer::AddMoney);

		// Game Speed
		PlayerInputComponent->BindAxis("GameSpeed", this, &AProjectMarsPlayer::UpdateGameSpeed);
	}
}