// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Framework/MarsGameStateBase.h"
#include "ProjectMars/Player/PlayerCameraPawn.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/UI/BaseHUD.h"

AMarsGameStateBase::AMarsGameStateBase()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
	
	UpdateCheckFrequency = 5.f;
	LastUpdateCheckTime = 0.f;

	MonthIndex = 1;
	CurrentDay = 1;
	CurrentTick = 0;
	LastTickCheck = 0;
}

// BeginPlay in the game state is called before BeginPlay in the player class. References will therefore not be initialised in BeginPlay here.
void AMarsGameStateBase::BeginPlay()
{
	Super::BeginPlay();
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

	UE_LOG(LogTemp, Warning, TEXT("Current Month: %d"), CurrentMonth);
}

void AMarsGameStateBase::UpdateGameTime()
{
	if(Player->bHasChosenFaction == false) { return; }
	
	// Updates set to every 5 seconds
	if(CurrentDay == CalculateMaxDaysInMonthNum() && Player)
	{	
		// Updates the info such as treasury, manpower, political power etc. on a monthly basis
		Player->UpdatePlayerFactionInfo();
		
		LastUpdateCheckTime = GetWorld()->GetTimeSeconds();

		// BUG: Game not starting on correct month.
		UpdateMonth();		
		CurrentDay = 1;
		CalculateMaxDaysInMonthNum();
	}

	CalculateCurrentDay();
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
		CurrentDay = FMath::Clamp(CurrentDay, 1, 31);
		return 31;
	}
	if(CurrentMonth == EMonthOfYear::February)
	{
		CurrentDay = FMath::Clamp(CurrentDay, 1, 28);
		return 28;
	}
	else
	{
		CurrentDay = FMath::Clamp(CurrentDay, 1, 30);
		return 30;
	}
}

void AMarsGameStateBase::CalculateTickRate()
{
	CurrentTick++;
	if(GetWorld()->TimeSince(LastTickCheck) >= 1)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Tick rate: %f"), CurrentTick);
		TickRate = CurrentTick;		
		CurrentTick = 0.f;
		LastTickCheck = GetWorld()->GetTimeSeconds();
	}
}

// BUG: Partly works, issues with months always having 30 days (apart from feb).
// BUG: When changing speed of game, days of the month don't modify their speed appropriately so we can stay on 31st for a few days before changing to next month.
void AMarsGameStateBase::CalculateCurrentDay()
{
	const float DaysPerSecond = UpdateCheckFrequency / CalculateMaxDaysInMonthNum();

	if(GetWorld()->TimeSince(LastDaysPerTickCheck) >= DaysPerSecond)
	{
		// BUG: Counter misses out 1 day of the month - the 1st or the last depending on where I put this UE_LOG
		UE_LOG(LogTemp, Warning, TEXT("CurrentDay: %d"), CurrentDay);
		++CurrentDay;
		
		LastDaysPerTickCheck = GetWorld()->GetTimeSeconds();	
	}
}

void AMarsGameStateBase::InitialiseReferences(APlayerCameraPawn* InitPlayer)
{
	Player = InitPlayer;
	
	if(!Player)
	{
		UE_LOG(LogTemp, Error, TEXT("Player is NULL"));
		return;
	}

	PlayerController = Cast<ABasePlayerController>(Player->GetController());
	if(!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController is NULL"));
		return;
	}

	BaseHUD = Cast<ABaseHUD>(PlayerController->GetHUD());
	if(!BaseHUD)
	{
		UE_LOG(LogTemp, Error, TEXT("BaseHUD is NULL"));
		return;
	}
}
