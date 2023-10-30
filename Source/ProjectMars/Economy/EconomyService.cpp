// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyService.h"

#include "FinanceCalculator.h"
#include "Data/EconomyData.h"
#include "ProjectMars/Civic/Tax/TaxService.h"

UEconomyService::UEconomyService(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	EconomyData(NewObject<UEconomyData>()),
	TaxService(NewObject<UTaxService>()),
	FinanceCalculator(NewObject<UFinanceCalculator>())
{
}

void UEconomyService::UpdateTreasury()
{
	// Calculate sum of income
	const int32 GrossIncome = FinanceCalculator->CalculateGrossIncome(IncomeSources);
	EconomyData->SetGrossIncome(GrossIncome);

	// Calculate expenses
	const int32 Expenses = FinanceCalculator->CalculateExpenses(ExpenseSources);
	EconomyData->SetExpenses(Expenses);
	
	// Calculate net income
	const int32 NetIncome = FinanceCalculator->CalculateNetIncome(
		EconomyData->GetSumOfIncome(),
		EconomyData->GetExpenses());
	EconomyData->SetNetIncome(NetIncome);

	// Calculate treasury
	const int32 UpdatedTreasury = EconomyData->GetTreasury() + EconomyData->GetNetIncome();
	EconomyData->SetTreasury(UpdatedTreasury);
}

UEconomyData* UEconomyService::GetEconomyData() const
{
	return EconomyData;
}

const TMap<EIncomeType, int32>& UEconomyService::GetIncomeSources() const
{
	return IncomeSources;
}

const TMap<EExpenseType, int32>& UEconomyService::GetExpenseSources() const
{
	return ExpenseSources;
}

void UEconomyService::InitialiseMonetarySources()
{
	IncomeSources.Empty();
	ExpenseSources.Empty();
	
	for (EIncomeType Type : TEnumRange<EIncomeType>())
	{
		IncomeSources.Add(Type, 500);
	}
	for (EExpenseType Type :  TEnumRange<EExpenseType>())
	{
		ExpenseSources.Add(Type, 250);
	}
}

void UEconomyService::UpdateTax(const int32 TotalTaxablePops) const
{
	TaxService->SetTaxIncome(TotalTaxablePops * TaxService->GetBaseValueTax());
}
