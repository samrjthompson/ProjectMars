// Fill out your copyright notice in the Description page of Project Settings.


#include "MarsGameStateBase.h"

#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/UI/BaseHUD.h"
#include "ProjectMars/Factions/FactionBase.h"
#include "ProjectMars/Controllers/AIControllerBase.h"

AMarsGameStateBase::AMarsGameStateBase()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
	
	UpdateCheckFrequency = 5.f;
	LastUpdateCheckTime = 0.f;

	// Starts on Feb because if we start on Jan the year gets updated straight away due to the condition for updating the year being 1st of Jan
	CurrentMonth = EMonthOfYear::February;
	MonthIndex = 2;
	
	CurrentDay = 1;
	
	CurrentTick = 0;
	LastTickCheck = 0;

	// Arbitrary start date at the moment, should change this if suits the historical background
	StartYear = 304;

	CurrentYear = FMath::Clamp(CurrentYear, 1, StartYear);
	CurrentYear = StartYear;
}

// BeginPlay in the game state is called before BeginPlay in the player class. References will therefore not be initialised in BeginPlay here.
void AMarsGameStateBase::BeginPlay()
{
	Super::BeginPlay();

	//PopulateFactionStartingInformation();
	CreateArrayOfAvailableFactions();
	
	LastTickCheck = GetWorld()->GetTimeSeconds();
	LastDaysPerTickCheck = GetWorld()->GetTimeSeconds();
}

void AMarsGameStateBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CalculateTickRate();
	
	UpdateGameTime();
}

void AMarsGameStateBase::UpdateMonth()
{
	switch (MonthIndex)
	{
	case 1 : CurrentMonth = EMonthOfYear::January;
		break;

	case 2 : CurrentMonth = EMonthOfYear::February;
		break;

	case 3 : CurrentMonth = EMonthOfYear::March;
		break;

	case 4 : CurrentMonth = EMonthOfYear::April;
		break;

	case 5 : CurrentMonth = EMonthOfYear::May;
		break;

	case 6 : CurrentMonth = EMonthOfYear::June;
		break;

	case 7 : CurrentMonth = EMonthOfYear::July;
		break;

	case 8 : CurrentMonth = EMonthOfYear::August;
		break;
		
	case 9 : CurrentMonth = EMonthOfYear::September;
		break;

	case 10 : CurrentMonth = EMonthOfYear::October;
		break;

	case 11 : CurrentMonth = EMonthOfYear::November;
		break;

	case 12 : CurrentMonth = EMonthOfYear::December;
		break;		
	}

	if(MonthIndex < 13)
	{
		MonthIndex++;
	}
	if(MonthIndex >= 13)
	{
		MonthIndex = 1;	
	}
}

void AMarsGameStateBase::UpdateGameTime()
{
	// We don't want the GameTime to update if the player hasn't chosen a faction yet
	if(Player->bHasChosenFaction == false) { return; }

	if (PlayerController->bGameIsPaused == true)
	{
		return;
	}
	
	// Updates set to every 5 seconds
	if(CurrentDay == CalculateMaxDaysInMonthNum() + 1 || !bGameHasStarted)
	{
		/* The first month is 0 so that Player faction info isn't updated on the first day of the first month. Instead,
		 * it will be updated for the first time on the first day of the 2nd month and every 1st of the month from then
		 * on. */
		if(MonthsInGame > 0)
		{
			// TODO: Update array of players incl AI
			// Updates the info such as treasury, manpower, political power etc. on a monthly basis
			if(PlayerArray.IsValidIndex(0))
			{
				for (int32 i = 0; i < PlayerArray.Num(); i++)
				{
					PlayerArray[i]->UpdatePlayerFactionInfo();
				}
			}
		}
		
		LastUpdateCheckTime = GetWorld()->GetTimeSeconds();

		UpdateMonth();
		MonthsInGame++;
		CurrentDay = 1;
		CalculateMaxDaysInMonthNum();

		if(CurrentDay == 1 && CurrentMonth == EMonthOfYear::January && CurrentYear > 1)
		{
			CurrentYear--;
			BaseHUD->DateSuffix = "BCE";
		}
		if(CurrentDay == 1 && CurrentMonth == EMonthOfYear::January && CurrentYear <= 1)
		{
			CurrentYear++;
			BaseHUD->DateSuffix = "CE";
		}

		// Initiate counting of days
		if(!bGameHasStarted) { bGameHasStarted = true; }
	}

	if(bGameHasStarted)
	{
		CalculateCurrentDay();
	}
}

int32 AMarsGameStateBase::CalculateMaxDaysInMonthNum()
{
	if(	CurrentMonth == EMonthOfYear::January ||
		CurrentMonth == EMonthOfYear::March ||
		CurrentMonth == EMonthOfYear::May ||
		CurrentMonth == EMonthOfYear::July ||
		CurrentMonth == EMonthOfYear::August ||
		CurrentMonth == EMonthOfYear::October ||
		CurrentMonth == EMonthOfYear::December)
	{
		// CurrentDay = FMath::Clamp(CurrentDay, 1, 31);
		return 31;
	}
	if(CurrentMonth == EMonthOfYear::February)
	{
		// CurrentDay = FMath::Clamp(CurrentDay, 1, 28);
		return 28;
	}
	else
	{
		//CurrentDay = FMath::Clamp(CurrentDay, 1, 30);
		return 30;
	}
}

FString AMarsGameStateBase::GetCurrentMonthName() const
{
	// No need to have a break statement due to return statement
	switch (CurrentMonth)
	{
		case EMonthOfYear::January : return "Jan";

		case EMonthOfYear::February : return "Feb";

		case EMonthOfYear::March : return "Mar";
		
		case EMonthOfYear::April : return "Apr";

		case EMonthOfYear::May : return "May";

		case EMonthOfYear::June : return "Jun";

		case EMonthOfYear::July : return "Jul";

		case EMonthOfYear::August : return "Aug";

		case EMonthOfYear::September : return "Sep";

		case EMonthOfYear::October : return "Oct";

		case EMonthOfYear::November : return "Nov";

		case EMonthOfYear::December : return "Dec";
	}

	return "NONE";
}

void AMarsGameStateBase::CalculateTickRate()
{
	CurrentTick++;
	if(GetWorld()->TimeSince(LastTickCheck) >= 1)
	{
		TickRate = CurrentTick;		
		CurrentTick = 0.f;
		LastTickCheck = GetWorld()->GetTimeSeconds();
		BaseHUD->FPSNum = FMath::FloorToInt(TickRate);
	}
}

void AMarsGameStateBase::CalculateCurrentDay()
{
	const float DaysPerSecond = UpdateCheckFrequency / CalculateMaxDaysInMonthNum();

	if(GetWorld()->TimeSince(LastDaysPerTickCheck) >= DaysPerSecond)
	{		
		++CurrentDay;	
		LastDaysPerTickCheck = GetWorld()->GetTimeSeconds();	
	}
}

void AMarsGameStateBase::InitialiseReferences(AProjectMarsPlayer* InitPlayer)
{
	Player = InitPlayer;
	
	if(!Player)
	{
		UE_LOG(LogTemp, Error, TEXT("Player is NULL"));
		return;
	}

	if (!Player->IsPlayerControlled()) { return; }
	
	// If player is controlled by player
	if(Player->IsPlayerControlled())
	{
		PlayerController = Cast<ABasePlayerController>(Player->GetController());
		if (!PlayerController)
		{
			UE_LOG(LogTemp, Error, TEXT("PlayerController is NULL"));
			return;
		}
	}

	BaseHUD = Cast<ABaseHUD>(PlayerController->GetHUD());
	if(!BaseHUD)
	{
		UE_LOG(LogTemp, Error, TEXT("BaseHUD is NULL"));
		return;
	}
}

/* Creates a TMap of all factions with a key EFaction enums and creates another TMap of Available factions (which, before anyone has
 * chosen a faction is an exact copy of the TMap of all factions). With this I intend to find some way of creating all faction objects
 * with a key of an enum - then using the enum key to find the object and assign values from there. Hoping to also use this for assigning
 * a player a faction. */
void AMarsGameStateBase::CreateArrayOfAvailableFactions()
{
	for (int32 i = 0; i < (uint8)EFactionName::MAX; i++)
	{
		FFaction FactionObj;
		//FactionPtr = NewObject<FFaction>();
		EFactionName FactionKey = EFactionName(i);

		AllFactionsMap.Add(FactionKey, FactionObj);
	}
	
	PopulateFactionStartingInformation(AllFactionsMap);
	
	/* Will use the AvailableFactionsMap array (which is a pointer) to find the remaining available factions and assign them to the
	 * AI after the player/s have chosen their factions. */
	AvailableFactionsMap = &AllFactionsMap;
}

void AMarsGameStateBase::PopulateFactionStartingInformation(TMap<EFactionName, struct FFaction>& InitAllFactionsMap)
{
	/* ITALIAN */
	// Rome
	Rome = InitAllFactionsMap.Find(EFactionName::Rome);
	if (!Rome) { UE_LOG(LogTemp, Error, TEXT("Rome is nullptr in AMarsGameStateBase::PopulateFactionStartingInformation")); return; } // Null check
	
	Rome->Faction = EFactionName::Rome;
	Rome->FactionName = "Roman Republic";

	// Certain criteria allow for an increase in dev level - one being every 10,000 population (up to level 50)
	{
		const int32 StartingTotalPop = FMath::RandRange(50000, 55000);

		Rome->FactionPop.TotalPatricianPop = StartingTotalPop * 0.10;
		Rome->FactionPop.TotalPlebesPop = StartingTotalPop * 0.30;
		Rome->FactionPop.TotalProletariatPop = StartingTotalPop * 0.30;
		Rome->FactionPop.TotalForeignerPop = StartingTotalPop * 0.05;
		Rome->FactionPop.TotalSlavePopulation = StartingTotalPop * 0.25;

		UE_LOG(LogTemp, Warning, TEXT("Rome name: %s"), *RomeFaction.FactionName.ToString());
	}

	// Etruria
	Etruria = InitAllFactionsMap.Find(EFactionName::Etruria);
	if (!Etruria) { UE_LOG(LogTemp, Error, TEXT("Etruria is nullptr in AMarsGameStateBase::PopulateFactionStartingInformation")); return; } // Null check

	Etruria->Faction = EFactionName::Etruria;
	Etruria->FactionName = "Etruria";

	// Certain criteria allow for an increase in dev level - one being every 10,000 population (up to level 50)
	{
		const int32 StartingTotalPop = FMath::RandRange(50000, 55000);

		Etruria->FactionPop.TotalPatricianPop = StartingTotalPop * 0.10;
		Etruria->FactionPop.TotalPlebesPop = StartingTotalPop * 0.30;
		Etruria->FactionPop.TotalProletariatPop = StartingTotalPop * 0.30;
		Etruria->FactionPop.TotalForeignerPop = StartingTotalPop * 0.05;
		Etruria->FactionPop.TotalSlavePopulation = StartingTotalPop * 0.25;
	}


	/* NORTH AFRICAN */
	// Carthage

	Carthage = InitAllFactionsMap.Find(EFactionName::Carthage);
	if (!Carthage) { UE_LOG(LogTemp, Error, TEXT("Carthage is nullptr in AMarsGameStateBase::PopulateFactionStartingInformation")); return; } // Null check

	Carthage->Faction = EFactionName::Carthage;
	Carthage->FactionName = "Carthage";

	// Certain criteria allow for an increase in dev level - one being every 10,000 population (up to level 50)
	{
		const int32 StartingTotalPop = FMath::RandRange(50000, 55000);

		Carthage->FactionPop.TotalPatricianPop = StartingTotalPop * 0.10;
		Carthage->FactionPop.TotalPlebesPop = StartingTotalPop * 0.30;
		Carthage->FactionPop.TotalProletariatPop = StartingTotalPop * 0.30;
		Carthage->FactionPop.TotalForeignerPop = StartingTotalPop * 0.05;
		Carthage->FactionPop.TotalSlavePopulation = StartingTotalPop * 0.25;
	}
}

void AMarsGameStateBase::AssignAIFactions()
{
	if (!AvailableFactionsMap) { return; }

	TArray<FFaction> FactionArray;
	AvailableFactionsMap->GenerateValueArray(FactionArray);

	TArray<AProjectMarsPlayer*> AIPlayersArray;
	
	for (int32 i = 0; i < AvailableFactionsMap->Num(); i++)
	{
		AProjectMarsPlayer* AIPlayer = nullptr;
		AIPlayer = GetWorld()->SpawnActor<AProjectMarsPlayer>(AProjectMarsPlayer::StaticClass());
		AIPlayer->PlayerFaction = &FactionArray[i];
		AIPlayer->InitialiseAIComponents(AIPlayer);
		AIPlayer->SpawnDefaultController();
		AIPlayersArray.Emplace(AIPlayer);

		if(AIPlayer->GetController())
		{
			UE_LOG(LogTemp, Warning, TEXT("AI Controller: %s"), *AIPlayer->GetController()->GetName());
		}
		if(!AIPlayer->GetController())
		{
			UE_LOG(LogTemp, Warning, TEXT("AI has no controller!"));
		}
	}
	
	FactionArray.Empty();
}