// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Economy.generated.h"


USTRUCT()
struct FFactionEconomics
{
	GENERATED_BODY()

	FFactionEconomics();

	struct FPopulation* Population{ nullptr };
	

/////////////////////////////////////////////////////////////////
	// GENERAL

	int32 StartingTreasury{};
	int32 Treasury{};
	float GrossIncome{};
	float NetIncome{};
	float Expenses{};


/////////////////////////////////////////////////////////////////
	// TAXES

	float TaxIncome{};

	UPROPERTY(EditAnywhere, Category = "Taxes")
		float UpperClassTaxRate{ 0.02f };

	UPROPERTY(EditAnywhere, Category = "Taxes")
		float MiddleClassTaxRate{ 0.01f };

	UPROPERTY(EditAnywhere, Category = "Taxes")
		float LowerClassTaxRate{ 0.005f };

	UPROPERTY(EditAnywhere, Category = "Taxes")
		float ForeignerTaxRate{ 0.005f };

	// Function to calculate tax income
	void CollectTaxes(struct FPopulation& Obj);

	void SetTaxIncome();


/////////////////////////////////////////////////////////////////
	// TRADE

	float TotalValueOfExports{};
	float TotalValueOfImports{};


/////////////////////////////////////////////////////////////////
	/* TRIBUTES */

	float TributeIncome{};
	float OutgoingTributes{};


/////////////////////////////////////////////////////////////////
	/* OTHER */

	float LootingIncome{};


/////////////////////////////////////////////////////////////////
	/* MAINTENANCE */

	float ArmyMaintenance{};
	float FleetMaintenance{};
	float Wages{};
	float StateMaintenance{};
	float FortMaintenance{};


/////////////////////////////////////////////////////////////////
	/* ECONOMY */

		// Returns the net income of a player per month
	float GetNetIncome();

	// Returns the gross income of a player per month
	float GetGrossIncome();

	// Returns the total outgoings of a player per month
	float GetTotalOutgoings();

	// Adds the net income to the player's overall treasury on a monthly basis - can be negative or positive number
	void ApplyNetIncomeToTreasury();

	// If the player's treasury is less than 0, this will be true
	bool bHasADeficit;

	// If the player's income per month is less than 0, this will be true
	bool bHasNegativeIncome;

	float UpperClassIncome{};
	float MiddleClassIncome{};
	float LowerClassIncome{};
	float ForeignerIncome{};

	// Calculates the gross income of each class type
	void CalculateClassIncome();
};

UCLASS()
class PROJECTMARS_API AEconomy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEconomy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
