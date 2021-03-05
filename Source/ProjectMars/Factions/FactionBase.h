// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FactionBase.generated.h"

USTRUCT()
struct FBaseFactionData
{
	GENERATED_BODY()
	FBaseFactionData()
	{
		FactionName = "NONE";
	}

	// Name
	FName FactionName{};

	// Economy
	float Treasury{};
	float Income{};
	float Expenses{};
	float TaxIncome{};
	float TotalValueOfExports{};
	float TotalValueOfImports{};
	float LootingIncome{};

	// Population
	int32 TotalPopulation{};
	int32 Manpower{};

	// Politics
	float PoliticalPowerIncome{};
	float TotalPoliticalPower{};
	float TotalStability{};
	float StabilityChange{};
	float TotalTyranny{};
	float TyrannyChange{};

	// Military
	float TotalAggressiveExpansion{};
	float AggressiveExpansionChange{};
	float TotalWarExhaustion{};
	float WarExhaustionChange{};
	float TotalMilitaryXP{};
	float MilitaryXPChange{};

	// Maintenance
	float ArmyMaintenance{};
	float FleetMaintenance{};
	float Wages{};
	
};

UCLASS()
class PROJECTMARS_API UFactionBase : public UObject
{
	GENERATED_BODY()

	UFactionBase();

	FBaseFactionData BaseFactionData;
};
