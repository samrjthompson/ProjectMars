// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyManager.h"

#include "IncomeCalculator.h"
#include "IncomeSource.h"
#include "OutgoingsCalculator.h"
#include "ProjectMars/EconomyInfo.h"


UEconomyManager::UEconomyManager()
{
	// Data structs
	EconomyInfo = new FEconomyInfo;
	TradeIncomeSource = new FIncomeSource;

	// Calculators
	IncomeCalculator = NewObject<UIncomeCalculator>();
	OutgoingsCalculator = NewObject<UOutgoingsCalculator>();

	// Maps
	MapOfIncomeSources.Add(EIncomeSourceType::TradeIncome, TradeIncomeSource);
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

const TMap<EIncomeSourceType, FIncomeSource*>& UEconomyManager::GetMapOfIncomeSources() const
{
	return MapOfIncomeSources;
}

const TMap<EOutgoingsSourceType, int32>& UEconomyManager::GetMapOfOutgoingSources() const
{
	return MapOfOutgoingSources;
}

UEconomyManager* UEconomyManager::SetMapOfOutgoingSources(const TMap<EOutgoingsSourceType, int32>& MapOfOutgoingSourcesVar)
{
	this->MapOfOutgoingSources = MapOfOutgoingSourcesVar;
	return this;
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

UEconomyManager* UEconomyManager::SetMapOfIncomeSources(const TMap<EIncomeSourceType, FIncomeSource*>& MapOfIncomeSourcesVar)
{
	this->MapOfIncomeSources = MapOfIncomeSourcesVar;
	return this;
}


