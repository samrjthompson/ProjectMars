// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FinanceCalculator.generated.h"

enum class EIncomeType : uint8;
enum class EExpenseType : uint8;

/**
 * Calculates the finances of a faction.
 */
UCLASS()
class PROJECTMARS_API UFinanceCalculator : public UObject
{
	GENERATED_BODY()

public:
	int32 CalculateGrossIncome(const TMap<EIncomeType, int32>& IncomeSourcesVar) const;
	int32 CalculateNetIncome(const int32 GrossIncome, const int32 GrossOutgoings) const;
	int32 CalculateExpenses(const TMap<EExpenseType, int32>& ExpensesSourcesVar);
	
private:
	
};
