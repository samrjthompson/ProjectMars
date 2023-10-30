// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NationService.generated.h"

class UEconomyService;
class UPopulationService;
class UTaxService;
class UCivicService;

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UNationService : public UObject
{
	GENERATED_BODY()

public:
	explicit UNationService(const FObjectInitializer& ObjectInitializer);

	// Function
	void UpdateIncome() const;

	// Getters
	UCivicService* GetCivicService() const;

private:
	UPROPERTY()
	UCivicService* CivicService{ nullptr };
	
};
