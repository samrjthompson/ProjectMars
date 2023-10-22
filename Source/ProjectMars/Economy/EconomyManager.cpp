// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyManager.h"

#include "FinanceCalculator.h"
#include "ProjectMars/EconomyInfo.h"


UEconomyManager::UEconomyManager()
{
	// Data structs
	EconomyInfo = new FEconomyInfo;

	// Calculators
	FinanceCalculator = NewObject<UFinanceCalculator>();

	// Maps
	InitialiseIncomeSources();
}

FEconomyInfo* UEconomyManager::GetEconomyInfo() const
{
	return EconomyInfo;
}

const TMap<EIncomeType, int32>* UEconomyManager::GetIncomeSources() const
{
	return &IncomeSources;
}

UEconomyManager* UEconomyManager::SetEconomyInfo(FEconomyInfo* EconomyInfoVar)
{
	this->EconomyInfo = EconomyInfoVar;
	return this;
}

void UEconomyManager::UpdateTreasury() const
{
	// Calculate sum of income
	const int32 GrossIncome = FinanceCalculator->CalculateGrossIncome(IncomeSources);
	EconomyInfo->SetGrossIncome(GrossIncome);

	// Calculate sum of outgoings
	const int32 Outgoings = FinanceCalculator->CalculateExpenses(ExpenseSources);
	EconomyInfo->SetGrossOutgoings(Outgoings);
	
	// Calculate net income
	const int32 NetIncome = FinanceCalculator->CalculateNetIncome(
		EconomyInfo->GetSumOfIncome(),
		EconomyInfo->GetSumOfOutgoings());
	EconomyInfo->SetNetIncome(NetIncome);

	// Calculate treasury
	const int32 UpdatedTreasury = EconomyInfo->GetTreasury() + EconomyInfo->GetNetIncome();
	EconomyInfo->SetTreasury(UpdatedTreasury);
}

// Initialises map of income sources with enum keys and values set to 0 by default
void UEconomyManager::InitialiseIncomeSources()
{
	for (EIncomeType Type : TEnumRange<EIncomeType>())
	{
		IncomeSources.Add(Type, 0);
	}
}


