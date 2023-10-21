// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyManager.h"

#include "IncomeCalculator.h"
#include "ProjectMars/EconomyInfo.h"


UEconomyManager::UEconomyManager()
{
	EconomyInfo = new FEconomyInfo;
	IncomeCalculator = NewObject<UIncomeCalculator>();
}

FEconomyInfo* UEconomyManager::GetEconomyInfo() const
{
	return EconomyInfo;
}

UEconomyManager* UEconomyManager::SetEconomyInfo(FEconomyInfo* EconomyInfoVar)
{
	this->EconomyInfo = EconomyInfoVar;
	return this;
}

void UEconomyManager::UpdateTreasury() const
{
	// Calculate sum of income
	const int32 GrossIncome = IncomeCalculator->CalculateGrossIncome(MapOfIncomeSources);
	EconomyInfo->SetGrossIncome(GrossIncome);
	
	// Calculate net income
	const int32 NetIncome = IncomeCalculator->CalculateNetIncome(
		EconomyInfo->GetSumOfIncome(),
		EconomyInfo->GetSumOfOutgoings());
	EconomyInfo->SetNetIncome(NetIncome);

	// Calculate treasury
	const int32 UpdatedTreasury = EconomyInfo->GetTreasury() + EconomyInfo->GetNetIncome();
	EconomyInfo->SetTreasury(UpdatedTreasury);
}

const UIncomeCalculator* UEconomyManager::GetIncomeCalculator() const
{
	return IncomeCalculator;
}

UEconomyManager* UEconomyManager::SetIncomeCalculator(UIncomeCalculator* IncomeCalculatorVar)
{
	this->IncomeCalculator = IncomeCalculatorVar;
	return this;
}

const TMap<EIncomeSourceType, int32>& UEconomyManager::GetMapOfIncomeSources() const
{
	return MapOfIncomeSources;
}

UEconomyManager* UEconomyManager::SetMapOfIncomeSources(const TMap<EIncomeSourceType, int32>& MapOfIncomeSourcesVar)
{
	this->MapOfIncomeSources = MapOfIncomeSourcesVar;
	return this;
}


