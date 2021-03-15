// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMarsPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
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

// Called when the game starts or when spawned
void AProjectMarsPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	CreateArrayOfAvailableFactions();
	InitialiseGameStateRefs();

	/*UGameplayStatics::OpenLevel(GetWorld(), "ChooseFaction");
	CurrentLevel = GetWorld()->GetMapName();*/
	
	BasePlayerController = Cast<ABasePlayerController>(GetController());
	if(BasePlayerController)
	{
		BaseHUD = Cast<ABaseHUD>(BasePlayerController->GetHUD());
	}
	if(!BasePlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("BasePlayerController is nullptr - AProjectMarsPlayer::BeginPlay"));
	}
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
		MarsGameStateBase->InitialiseReferences(this);
	}
	if(!MarsGameStateBase)
	{
		UE_LOG(LogTemp, Error, TEXT("MarsGameStateBase is NULL!"))
	}
}

/* Creates a TMap of all factions with a key EFaction enums and creates another TMap of Available factions (which, before anyone has
 * chosen a faction is an exact copy of the TMap of all factions). With this I intend to find some way of creating all faction objects
 * with a key of an enum - then using the enum key to find the object and assign values from there. Hoping to also use this for assigning
 * a player a faction. */
void AProjectMarsPlayer::CreateArrayOfAvailableFactions()
{
	TArray<EFactionName> FactionEnums;
	// TArray<ETestType> EnumTestArray;

	/*for(int32 i = 0; i < ETestType::MAX; i++)
	{
		EnumTestArray.AddUnique(ETestType(i));
	}*/
	
	for(int32 i = 0; i < (uint8)EFactionName::MAX; i++)
	{
		FactionEnums.Add(EFactionName(i));
	}
	for(int32 i = 0; i < (uint8)EFactionName::MAX; i++)
	{
		FFaction FactionObj;
		//FactionPtr = NewObject<FFaction>();
		EFactionName FactionKey = EFactionName(i);

		AllFactionsMap.Add(FactionKey, FactionObj);
	}

	// Will use the AvailableFactionsMap to find the remaining available factions and assign them to the AI after the player/s have chosen their factions
	AvailableFactionsMap = AllFactionsMap;
	// PlayerFaction = AvailableFactionsMap.Find(EFactionName::Rome);
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
	// InitialisePlayerFaction(EFactionName::Rome);

	PlayerFaction = AvailableFactionsMap.Find(EFactionName::Rome);
	AvailableFactionsMap.Remove(EFactionName::Rome);

	PlayerFaction->Faction = EFactionName::Rome;
	PlayerFaction->FactionName = "Roman Republic";

	// Certain criteria allow for an increase in dev level - one being every 10,000 population (up to level 50)
	const int32 StartingDevelopmentLevel = 5;
	const int32 StartingTotalPop = FMath::RandRange(StartingDevelopmentLevel * 10000, (StartingDevelopmentLevel * 10000) + 5000);

	PlayerFaction->FactionPop.TotalPatricianPop = StartingTotalPop * 0.095;
	PlayerFaction->FactionPop.TotalPlebesPop = StartingTotalPop * 0.2;
	PlayerFaction->FactionPop.TotalProletariatPop = StartingTotalPop * 0.6;
	PlayerFaction->FactionPop.TotalForeignerPop = StartingTotalPop * 0.035;
	PlayerFaction->FactionPop.TotalSlavePopulation = StartingTotalPop * 0.07;

	UE_LOG(LogTemp, Warning, TEXT("Rome name: %s"), *PlayerFaction->FactionName.ToString());

	InitialisePlayerFaction(EFactionName::Rome);
}

void AProjectMarsPlayer::ChooseEtruria()
{
	if(bHasChosenFaction) { return; }
	InitialisePlayerFaction(EFactionName::Etruria);
}

void AProjectMarsPlayer::ChooseCarthage()
{
	if(bHasChosenFaction) { return; }
	InitialisePlayerFaction(EFactionName::Carthage);
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