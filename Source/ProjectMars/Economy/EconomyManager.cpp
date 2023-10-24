// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyManager.h"

#include "FinanceCalculator.h"
#include "ProjectMars/Economy/Data/EconomyData.h"


UEconomyManager::UEconomyManager()
{
	// Data structs
	EconomyData = new FEconomyData;

	// Calculators
	FinanceCalculator = NewObject<UFinanceCalculator>();

	// Maps
	InitialiseIncomeSources();
}

FEconomyData* UEconomyManager::GetEconomyData() const
{
	return EconomyData;
}

const TMap<EIncomeType, int32>* UEconomyManager::GetIncomeSources() const
{
	return &IncomeSources;
}

UEconomyManager* UEconomyManager::SetEconomyData(FEconomyData* EconomyDataVar)
{
	this->EconomyData = EconomyDataVar;
	return this;
}

void UEconomyManager::UpdateTreasury() const
{
	// Calculate sum of income
	const int32 GrossIncome = FinanceCalculator->CalculateGrossIncome(IncomeSources);
	EconomyData->SetGrossIncome(GrossIncome);

	// Calculate sum of outgoings
	const int32 Outgoings = FinanceCalculator->CalculateExpenses(ExpenseSources);
	EconomyData->SetGrossOutgoings(Outgoings);
	
	// Calculate net income
	const int32 NetIncome = FinanceCalculator->CalculateNetIncome(
		EconomyData->GetSumOfIncome(),
		EconomyData->GetSumOfOutgoings());
	EconomyData->SetNetIncome(NetIncome);

	// Calculate treasury
	const int32 UpdatedTreasury = EconomyData->GetTreasury() + EconomyData->GetNetIncome();
	EconomyData->SetTreasury(UpdatedTreasury);
}

// Initialises map of income sources with enum keys and values set to 0 by default
void UEconomyManager::InitialiseIncomeSources()
{
	for (EIncomeType Type : TEnumRange<EIncomeType>())
	{
		IncomeSources.Add(Type, 0);
	}
}


