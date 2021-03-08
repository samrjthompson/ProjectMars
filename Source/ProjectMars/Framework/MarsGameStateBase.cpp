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
}

// BeginPlay in the game state is called before BeginPlay in the player class. References will therefore not be initialised in BeginPlay here.
void AMarsGameStateBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMarsGameStateBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

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
	// Updates set to every 5 seconds
	if(GetWorld()->TimeSince(LastUpdateCheckTime) >= UpdateCheckFrequency && Player)
	{		
		if(Player->bHasChosenFaction == false) { return; }

		UE_LOG(LogTemp, Warning, TEXT("UpdatePlayerFactionInfo CALLED!"));		

		// Updates the info such as treasury, manpower, political power etc. on a monthly basis
		Player->UpdatePlayerFactionInfo();
		
		LastUpdateCheckTime = GetWorld()->GetTimeSeconds();

		UpdateMonth();

		/*if(!CampaignDateTimePtr) { return; } // NULL Check
		CampaignDateTimePtr->UpdateDayOfMonth(CurrentMonth);*/
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
