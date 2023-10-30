// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Population/PopulationService.h"
#include "UObject/Object.h"
#include "CivicService.generated.h"

class UEconomyService;
class UPopulationService;

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UCivicService : public UObject
{
	GENERATED_BODY()

public:
	explicit UCivicService(const FObjectInitializer& ObjectInitializer);

	// Functions
	void UpdateIncome() const;

	// Getters
	UFUNCTION()
	UEconomyService* GetEconomyService() const;

	UFUNCTION()
	UPopulationService* GetPopulationService() const;

private:
	UPROPERTY()
	UEconomyService* EconomyService{ nullptr };
	
	UPROPERTY()
	UPopulationService* PopulationService{ nullptr };
};
