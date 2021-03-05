// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FactionBase.generated.h"

// Seem to have to forward declare the enums
enum class EFaction : uint8;
enum class ECultureGroup : uint8;
enum class ECulture : uint8;

struct FBaseFactionData;

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
		StartingTreasury = 5000.00f;
	}

	// Name
	FName FactionName{};

	// Economy
	float StartingTreasury{};
	float Treasury{};
	float GrossIncome{};
	float NetIncome{};
	float Expenses{};
	float TaxIncome{};
	float TotalValueOfExports{};
	float TotalValueOfImports{};
	float LootingIncome{};
	float TributeIncome{};
	float StateMaintenance{};
	float FortMaintenance{};
	float OutgoingTributes{};

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

	// Economy
	virtual void UpdateCurrentIncome();

	virtual FBaseFactionData GetRefToFactionData();

protected:
	FName FactionName{};

	EFaction FactionType;
	ECultureGroup CultureGroup;
	ECulture Culture;


	FBaseFactionData BaseFactionData;
	
	float CurrentFactionGrossIncome{};
    float CurrentFactionExpenses{};
    float CurrentFactionNetIncome{};

};
