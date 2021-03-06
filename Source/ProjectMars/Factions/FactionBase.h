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
struct FFactionEconomics
{
	GENERATED_BODY()

	FFactionEconomics()
	{
		StartingTreasury = 5000.00f;
		Treasury = StartingTreasury;
	}

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
	
	// Maintenance
	float ArmyMaintenance{};
	float FleetMaintenance{};
	float Wages{};

	// Economic Calculations
	float GetNetIncome();
	float GetGrossIncome();
	float GetTotalOutgoings();
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
	float StartingTreasury{};
	float Treasury{};

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


	
};

UCLASS()
class PROJECTMARS_API UFactionBase : public UObject
{
	GENERATED_BODY()

	friend class APlayerCameraPawn;
	friend class ABaseHUD;

public:
	UFactionBase();

	inline FName GetBaseFactionName() const { return FactionName; }

	virtual FBaseFactionData& GetRefToFactionData();
	virtual FFactionEconomics& GetRefToEconomicsData();

protected:
	FName FactionName{};

	EFaction FactionType;
	ECultureGroup CultureGroup;
	ECulture Culture;

	// Objects by value of faction data structs
	FBaseFactionData BaseFactionData;
	FFactionEconomics FactionEconomics;
};
