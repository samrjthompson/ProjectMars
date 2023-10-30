// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PopulationService.generated.h"

class UPopulationData;

/**
 * Performs various functions on behalf of the PopulationController class
 */
UCLASS()
class PROJECTMARS_API UPopulationService : public UObject
{
	GENERATED_BODY()

public:
	explicit UPopulationService(const FObjectInitializer& ObjectInitializer);

	// Functions	
	UFUNCTION()
	int32 CalculateTaxablePopNum(float TaxablePopPercentageVar) const;

	// Getters
	UPopulationData* GetPopulationData() const;

private:
	UPROPERTY()
	UPopulationData* PopulationData{ nullptr };
	
};
