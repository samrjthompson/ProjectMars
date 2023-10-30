// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PopulationData.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UPopulationData : public UObject
{
	GENERATED_BODY()

public:
	explicit UPopulationData(const FObjectInitializer& ObjInitializer);

	// Functions
	UFUNCTION()
	int32 CalculateFightingAgeMales() const;

	// Getters
	UFUNCTION()
	int32 GetCurrentTotalPopNum() const;
	UFUNCTION()
	int32 GetCurrentCitizenPopNum() const;
	UFUNCTION()
	int32 GetCurrentNonCitizenPopNum() const;
	UFUNCTION()
	int32 GetCurrentAlliedClientPopNum() const;
	UFUNCTION()
	int32 GetCurrentSlavePopNum() const;
	UFUNCTION()
	int32 GetCurrentForeignerPopNum() const;

	// Getters

	// Setters

private:
	const int32 StartingTotalPopNum{};
	int32 CurrentTotalPopNum;
	float CitizenPercentage;
	const int32 StartingCitizenPopNum{};
	int32 CurrentCitizenPopNum;
	float FightingAgeMalePercentage;
	const int32 StartingNonCitizenPopNum{};
	int32 CurrentNonCitizenPopNum;
	const int32 StartingAlliedClientPopNum{};
	int32 CurrentAlliedClientPopNum;
	const int32 StartingSlavePopNum{};
	int32 CurrentSlavePopNum;
	const int32 StartingForeignerPopNum{};
	int32 CurrentForeignerPopNum;
};
