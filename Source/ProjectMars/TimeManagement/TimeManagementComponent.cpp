// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/TimeManagement/TimeManagementComponent.h"

#include "ProjectMars/Components/PlayerManagement/PlayerManagerComponent.h"
#include "ProjectMars/Framework/MarsGameStateBase.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/Framework/DelegateManager.h"
#include "ProjectMars/UI/BaseHUD.h"


// Sets default values for this component's properties
UTimeManagementComponent::UTimeManagementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	UpdateCheckFrequency = 5.0f;
	LastUpdateCheckTime = 0.0;

	CurrentMonth = EMonthOfYear::February;
	MonthIndex = 2;
	
	CurrentDay = 1;
	CurrentDisplayDay = CurrentDay;
	
	CurrentTick = 0;
	LastTickCheck = 0;

	StartYear = 304;

	CurrentYear = StartYear;
	CurrentDisplayYear = CurrentYear;
	CurrentEra = EEra::BCE;
}

// Called when the game starts
void UTimeManagementComponent::BeginPlay()
{
	Super::BeginPlay();

	GameState = Cast<AMarsGameStateBase>(GetWorld()->GetGameState());
	ensure(GameState);

	DelegateManager = GameState->GetDelegateManager();
	DelegateManager->OnPlayerInitialisation.AddDynamic(this, &UTimeManagementComponent::InitialiseRefs);
	PlayerManagerComponent = GameState->GetPlayerManagerComponent();
	
	LastTickCheck = FPlatformTime::Seconds();
	LogCheck = FPlatformTime::Seconds();	
}

// Called every frame
void UTimeManagementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CalculateTickRate();
	UpdateGameTime();
}

void UTimeManagementComponent::UpdateMonth()
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

	if(MonthsInGame > 0) DelegateManager->OnMonthlyUpdate.Broadcast();
}

void UTimeManagementComponent::UpdateGameTime()
{
	// We don't want the GameTime to update if the player hasn't chosen a faction yet
	if(Player->bHasChosenFaction == false) return;

	if (PlayerController->bGameIsPaused == true) return;

	// Update month and year
	if(CurrentDay == GetMaxDaysInMonth() + 1 || !bGameHasStarted)
	{
		// Month
		UpdateMonth();
		CalculateMaxDaysInMonth();
		MonthsInGame++;

		// Day
		CurrentDay = 1;
		CurrentDisplayDay = 1;		

		// Year
		if(CurrentEra == EEra::BCE && CurrentDay == 1 && CurrentMonth == EMonthOfYear::January && CurrentYear > 1)
		{
			// If current era is BCE...

			BaseHUD->SetDateSuffix("BCE");
			CurrentYear--;
			
			if(CurrentYear != 0) CurrentDisplayYear = CurrentYear;
		}
		if(CurrentDay == 1 && CurrentMonth == EMonthOfYear::January && CurrentYear < 1)
		{
			// If current era is CE...
		
			// Prevents years from entering minuses
			if(CurrentYear < 0)	CurrentYear = 0;
			
			CurrentEra = EEra::CE;
			BaseHUD->SetDateSuffix("CE");
			CurrentYear++;
			
			if(CurrentYear != 0) CurrentDisplayYear = CurrentYear;
		}

		// Initiate counting of days
		if(!bGameHasStarted) bGameHasStarted = true;
	}

	// Update day
	if(bGameHasStarted) CalculateCurrentDay();
}

int32 UTimeManagementComponent::GetMaxDaysInMonth() const
{
	return MaxDaysInMonth;
}

float UTimeManagementComponent::GetTickRate() const
{
	return TickRate;
}

int32 UTimeManagementComponent::GetCurrentDay() const
{
	return CurrentDay;
}

FString UTimeManagementComponent::ConvertCurrentMonthToString() const
{
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

int32 UTimeManagementComponent::GetCurrentYear() const
{
	return CurrentYear;
}

void UTimeManagementComponent::CalculateTickRate()
{
	CurrentTick++;
	if(GetTimeSince(LastTickCheck) >= 1)
	{
		LastTickCheck = FPlatformTime::Seconds();
		BaseHUD->FPSNum = FMath::FloorToInt(CurrentTick);
		CurrentTick = 0.f;
	}
}

void UTimeManagementComponent::CalculateCurrentDay()
{
	const float SecondsPerDay = UpdateCheckFrequency / GetMaxDaysInMonth();

	if(GetTimeSince(LastUpdateCheckTime) >= SecondsPerDay)
	{		
		CurrentDay++;
		if (CurrentDay <= GetMaxDaysInMonth()) CurrentDisplayDay = CurrentDay;

		LastUpdateCheckTime = FPlatformTime::Seconds();	
	}
}

void UTimeManagementComponent::CalculateMaxDaysInMonth()
{
	if(	CurrentMonth == EMonthOfYear::January ||
	CurrentMonth == EMonthOfYear::March ||
	CurrentMonth == EMonthOfYear::May ||
	CurrentMonth == EMonthOfYear::July ||
	CurrentMonth == EMonthOfYear::August ||
	CurrentMonth == EMonthOfYear::October ||
	CurrentMonth == EMonthOfYear::December)
	{
		MaxDaysInMonth = 31;
		return;
	}
	if(CurrentMonth == EMonthOfYear::February)
	{
		MaxDaysInMonth = 28;
		return;
	}
	
	MaxDaysInMonth = 30;
}

double UTimeManagementComponent::GetTimeSince(double StartTime)
{
	return FPlatformTime::Seconds() - StartTime;
}

AProjectMarsPlayer* UTimeManagementComponent::GetPlayer() const
{
	return Player;
}

void UTimeManagementComponent::SetPlayer(AProjectMarsPlayer* PlayerPtr)
{
	Player = PlayerPtr;
}

ABasePlayerController* UTimeManagementComponent::GetPlayerController() const
{
	return PlayerController;
}

void UTimeManagementComponent::SetPlayerController(ABasePlayerController* PlayerControllerVal)
{
	PlayerController = PlayerControllerVal;
}

ABaseHUD* UTimeManagementComponent::GetBaseHUD() const
{
	return BaseHUD;
}

void UTimeManagementComponent::SetBaseHUD(ABaseHUD* BaseHUDVal)
{
	BaseHUD = BaseHUDVal;
}

void UTimeManagementComponent::LogEveryXSeconds(double Val)
{
	if(FPlatformTime::Seconds() - LogCheck >= Val)
	{
		UE_LOG(LogTemp, Warning, TEXT("Log"));
		LogCheck = FPlatformTime::Seconds();
	}
}

void UTimeManagementComponent::InitialiseRefs()
{
	Player = GameState->GetPlayer();
	PlayerController = GameState->GetPlayerController();
	BaseHUD = GameState->GetBaseHUD();

	ensure(Player);
	ensure(PlayerController);
	ensure(BaseHUD);
}

void UTimeManagementComponent::SetLastUpdateCheckTime(double Time)
{
	LastUpdateCheckTime = Time;
}

void UTimeManagementComponent::SetUpdateCheckFrequency(float Freq)
{
	UpdateCheckFrequency = Freq;
}

UPlayerManagerComponent* UTimeManagementComponent::GetPlayerManagerComponent() const
{
	return PlayerManagerComponent;
}

int32 UTimeManagementComponent::GetCurrentDisplayDay() const
{
	return CurrentDisplayDay;
}

int32 UTimeManagementComponent::GetCurrentDisplayYear() const
{
	return CurrentDisplayYear;
}

