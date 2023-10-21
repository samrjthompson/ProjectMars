// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyManager.h"

#include "IncomeCalculator.h"
#include "OutgoingsCalculator.h"
#include "ProjectMars/EconomyInfo.h"


UEconomyManager::UEconomyManager()
{
	// Data structs
	EconomyInfo = new FEconomyInfo;

	// Calculators
	IncomeCalculator = NewObject<UIncomeCalculator>();
	OutgoingsCalculator = NewObject<UOutgoingsCalculator>();

	// Maps
	InitialiseMapOfIncomeSources();
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

	// Calculate sum of outgoings
	const int32 Outgoings = OutgoingsCalculator->CalculateOutgoings(MapOfOutgoingSources);
	EconomyInfo->SetGrossOutgoings(Outgoings);
	
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

const TMap<EIncomeType, int32>& UEconomyManager::GetMapOfIncomeSources() const
{
	return MapOfIncomeSources;
}

const TMap<EExpenditureType, int32>& UEconomyManager::GetMapOfOutgoingSources() const
{
	return MapOfOutgoingSources;
}

UEconomyManager* UEconomyManager::SetMapOfOutgoingSources(const TMap<EExpenditureType, int32>& MapOfOutgoingSourcesVar)
{
	this->MapOfOutgoingSources = MapOfOutgoingSourcesVar;
	return this;
}


// Initialises map of income sources with enum keys and values set to 0 by default
void UEconomyManager::InitialiseMapOfIncomeSources()
{
	for (EIncomeType Type : TEnumRange<EIncomeType>())
	{
		MapOfIncomeSources.Add(Type, 0);
	}
}

const UOutgoingsCalculator* UEconomyManager::GetOutgoingsCalculator() const
{
	return OutgoingsCalculator;
}

UEconomyManager* UEconomyManager::SetOutgoingsCalculator(UOutgoingsCalculator* OutgoingsCalculatorVar)
{
	this->OutgoingsCalculator = OutgoingsCalculatorVar;
	return this;
}

UEconomyManager* UEconomyManager::SetMapOfIncomeSources(const TMap<EIncomeType, int32>& MapOfIncomeSourcesVar)
{
	this->MapOfIncomeSources = MapOfIncomeSourcesVar;
	return this;
}


