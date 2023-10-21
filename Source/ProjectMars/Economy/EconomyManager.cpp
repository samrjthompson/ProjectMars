// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyManager.h"

#include "ProjectMars/EconomyInfo.h"


UEconomyManager::UEconomyManager()
{
	EconomyInfo = new FEconomyInfo;
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

const TArray<int32>& UEconomyManager::GetListOfIncomeSources() const
{
	return ListOfIncomeSources;
}

void UEconomyManager::UpdateTreasury() const
{
	CalculateNetIncome();
	int32 CurrentTreasury = EconomyInfo->GetTreasury();
	const int32 UpdatedTreasury = CurrentTreasury += EconomyInfo->GetNetIncome();
	EconomyInfo->SetTreasury(UpdatedTreasury);
}

void UEconomyManager::AddToListOfIncomeSources(const int32 IncomeSourceVar)
{
	ListOfIncomeSources.Add(IncomeSourceVar);
}

UEconomyManager* UEconomyManager::SetListOfIncomeSources(const TArray<int32>& ListOfIncomeSourcesVar)
{
	this->ListOfIncomeSources = ListOfIncomeSourcesVar;
	return this;
}

void UEconomyManager::CalculateSumOfIncome(const TArray<int32>& ListOfIncomeSourcesVar) const
{
	int32 TotalIncome{ 0 };
	for (const int32 IncomeSource : ListOfIncomeSourcesVar)
	{
		TotalIncome += IncomeSource;
	}
	EconomyInfo->SetSumOfIncome(TotalIncome);
}

void UEconomyManager::CalculateNetIncome() const
{
	const int32 TotalIncome = EconomyInfo->GetSumOfIncome();
	const int32 TotalOutgoings = EconomyInfo->GetSumOfOutgoings();
	
	CalculateSumOfIncome(ListOfIncomeSources);
	EconomyInfo->SetNetIncome(TotalIncome - TotalOutgoings);
}


