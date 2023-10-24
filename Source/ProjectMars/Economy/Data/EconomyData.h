// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EconomyData.generated.h"

USTRUCT()
struct PROJECTMARS_API FEconomyData
{
	GENERATED_BODY()

	FEconomyData();

	int32 GetTreasury() const;
	FEconomyData* SetTreasury(const int32 TreasuryVar);

	int32 GetExpenses() const;
	FEconomyData* SetExpenses(const int32 ExpensesVar);

	int32 GetSumOfIncome() const;
	FEconomyData* SetGrossIncome(const int32 GrossIncomeVar);

	int32 GetNetIncome() const;
	FEconomyData* SetNetIncome(const int32 NetIncomeVar);

private:
	int32 Treasury{};
	int32 Expenses{};
	int32 GrossIncome{};
	int32 NetIncome{};
};
