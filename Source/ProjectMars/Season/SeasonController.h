// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SeasonController.generated.h"

class UDelegateController;

/**
 * The owner of what the season is and maintainer
 */
UCLASS()
class PROJECTMARS_API USeasonController : public UObject
{
	GENERATED_BODY()

public:
	USeasonController();
	
	// Functions
	
	// Broadcasts a new season with the current season as a parameter
	UFUNCTION()
	void BroadcastNewSeasonEvent(const int32 TurnNumberVar);

	UFUNCTION()
	void PopulateListOfSeasons();

	UFUNCTION()
	void SubscribeToDelegateEvents(UDelegateController* DelegateControllerVar);

	UFUNCTION()
	void BroadcastNewYear();
	
	// Getters
	UFUNCTION()
	const TArray<FString>& GetListOfSeasons() const;

	// Setters
	UFUNCTION()
	USeasonController* SetDelegateController(UDelegateController* DelegateControllerVar);

private:
	// Functions
	UFUNCTION()
	void SetStartTurnSeason();

	// Properties
	UPROPERTY(EditAnywhere)
	FString CurrentSeason;

	UPROPERTY(EditAnywhere)
	FString StartingSeason;

	UPROPERTY(EditAnywhere)
	int32 SeasonIndex;

	UPROPERTY(EditAnywhere)
	TArray<FString> ListOfSeasons;

	UPROPERTY(EditAnywhere)
	int32 MaxNumberOfSeasons;

	UPROPERTY(EditAnywhere)
	int32 MaxSeasonIndex;

	UPROPERTY(EditAnywhere)
	UDelegateController* DelegateController{ nullptr };
};
