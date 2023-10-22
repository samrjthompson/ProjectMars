// Fill out your copyright notice in the Description page of Project Settings.


#include "FinanceCalculator.h"

int32 UFinanceCalculator::CalculateGrossIncome(const TMap<EIncomeType, int32>& IncomeSourcesVar) const
{
	int32 TotalIncome{ 0 };
	for (const auto IncomeSource : IncomeSourcesVar)
	{
		TotalIncome += IncomeSource.Value;;
	}
	return TotalIncome;
}

int32 UFinanceCalculator::CalculateNetIncome(const int32 GrossIncome, const int32 GrossOutgoings) const
{
	return GrossIncome - GrossOutgoings;
}

int32 UFinanceCalculator::CalculateExpenses(const TMap<EExpenseType, int32>& ExpensesSourcesVar)
{
	int32 TotalExpenses = 0;
	for (const auto ExpenseSource : ExpensesSourcesVar)
	{
		TotalExpenses += ExpenseSource.Value;
	}
	return TotalExpenses;
}
