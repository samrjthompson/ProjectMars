// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FactionBase.generated.h"

// Seem to have to forward declare the enums
enum class EFaction : uint8;
enum class ECultureGroup : uint8;
enum class ECulture : uint8;

UENUM()
enum class EFaction : uint8
{
	Rome	UMETA(DisplayName = "Rome"),
	Etruria		UMETA(DisplayName = "Etruria"),
	Carthage	UMETA(DisplayName = "Carthage")
};

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

public:
	UFactionBase();

	inline FName GetBaseFactionName() const { return FactionName; }

protected:
	FName FactionName{};

	EFaction FactionType;
	ECultureGroup CultureGroup;
	ECulture Culture;
};
