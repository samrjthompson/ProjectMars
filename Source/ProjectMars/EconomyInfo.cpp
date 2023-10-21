// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyInfo.h"


FEconomyInfo::FEconomyInfo()
{
	Treasury = 0;
}

FEconomyInfo::~FEconomyInfo()
{
}

int32 FEconomyInfo::GetTreasury() const
{
	return Treasury;
}

FEconomyInfo* FEconomyInfo::SetTreasury(const int32 TreasuryVar)
{
	Treasury = TreasuryVar;
	return this;
}

int32 FEconomyInfo::GetSumOfOutgoings() const
{
	return GrossOutgoings;
}

FEconomyInfo* FEconomyInfo::SetGrossOutgoings(const int32 GrossOutgoingsVar)
{
	this->GrossOutgoings = GrossOutgoingsVar;
	return this;
}

int32 FEconomyInfo::GetSumOfIncome() const
{
	return GrossIncome;
}

FEconomyInfo* FEconomyInfo::SetGrossIncome(const int32 GrossIncomeVar)
{
	this->GrossIncome = GrossIncomeVar;
	return this;
}

int32 FEconomyInfo::GetNetIncome() const
{
	return NetIncome;
}

FEconomyInfo* FEconomyInfo::SetNetIncome(const int32 NetIncomeVar)
{
	this->NetIncome = NetIncomeVar;
	return this;
}
