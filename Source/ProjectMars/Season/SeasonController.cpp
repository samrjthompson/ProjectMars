// Fill out your copyright notice in the Description page of Project Settings.


#include "SeasonController.h"

#include "Logging/StructuredLog.h"
#include "ProjectMars/Delegates/DelegateController.h"

USeasonController::USeasonController()
{
	SeasonIndex = 0;
	PopulateListOfSeasons();
	CurrentSeason = StartingSeason;
	UE_LOGFMT(LogTemp, Warning, "Creating season controller");
}

void USeasonController::CalculateCurrentSeason(const int32 TurnNumberVar)
{
	CurrentSeason = ListOfSeasons[SeasonIndex++];
	if (SeasonIndex > MaxSeasonIndex)
	{
		// Reset SeasonIndex
		SeasonIndex = 0;
	}
	DelegateController->OnNewSeason.Broadcast(CurrentSeason);
}

void USeasonController::PopulateListOfSeasons()
{
	// This will be populated from a JSON file
	ListOfSeasons = { "spring", "summer", "autumn", "winter" };
	StartingSeason = ListOfSeasons[0];
	MaxNumberOfSeasons = ListOfSeasons.Num();
	MaxSeasonIndex = MaxNumberOfSeasons - 1;
}

void USeasonController::SubscribeToDelegateEvents(UDelegateController* DelegateControllerVar)
{
	DelegateController->OnStartNewTurn.AddDynamic(this, &USeasonController::CalculateCurrentSeason);
}

void USeasonController::BroadcastNewYear()
{
	DelegateController->OnNewYear.Broadcast();
}

const TArray<FString>& USeasonController::GetListOfSeasons() const
{
	return ListOfSeasons;
}

USeasonController* USeasonController::SetDelegateController(UDelegateController* DelegateControllerVar)
{
	DelegateController = DelegateControllerVar;
	return this;
}
