// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyData.h"


FEconomyData::FEconomyData()
{
	Treasury = 0;
}

int32 FEconomyData::GetTreasury() const
{
	return Treasury;
}

FEconomyData* FEconomyData::SetTreasury(const int32 TreasuryVar)
{
	Treasury = TreasuryVar;
	return this;
}

int32 FEconomyData::GetSumOfOutgoings() const
{
	return GrossOutgoings;
}

FEconomyData* FEconomyData::SetGrossOutgoings(const int32 GrossOutgoingsVar)
{
	this->GrossOutgoings = GrossOutgoingsVar;
	return this;
}

int32 FEconomyData::GetSumOfIncome() const
{
	return GrossIncome;
}

FEconomyData* FEconomyData::SetGrossIncome(const int32 GrossIncomeVar)
{
	this->GrossIncome = GrossIncomeVar;
	return this;
}

int32 FEconomyData::GetNetIncome() const
{
	return NetIncome;
}

FEconomyData* FEconomyData::SetNetIncome(const int32 NetIncomeVar)
{
	this->NetIncome = NetIncomeVar;
	return this;
}
