// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EconomyData.generated.h"

/**
 * This class stores the data relating to a State's economy.
 */
UCLASS()
class PROJECTMARS_API UEconomyData : public UObject
{
	GENERATED_BODY()

public:
	UEconomyData();

	// Getters
	int32 GetTreasury() const;
	int32 GetExpenses() const;
	int32 GetSumOfIncome() const;
	int32 GetNetIncome() const;
	
	// Setters
	UEconomyData* SetTreasury(const int32 TreasuryVar);
	UEconomyData* SetExpenses(const int32 ExpensesVar);
	UEconomyData* SetGrossIncome(const int32 GrossIncomeVar);
	UEconomyData* SetNetIncome(const int32 NetIncomeVar);

private:
	int32 Treasury{};
	int32 Expenses{};
	int32 GrossIncome{};
	int32 NetIncome{};
};
