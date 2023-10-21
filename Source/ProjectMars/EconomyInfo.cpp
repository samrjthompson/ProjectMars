// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyInfo.h"


FEconomyInfo::FEconomyInfo()
{
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
	return SumOfOutgoings;
}

FEconomyInfo* FEconomyInfo::SetSumOfOutgoings(const int32 SumOfOutgoingsVar)
{
	this->SumOfOutgoings = SumOfOutgoingsVar;
	return this;
}

int32 FEconomyInfo::GetSumOfIncome() const
{
	return SumOfIncome;
}

FEconomyInfo* FEconomyInfo::SetSumOfIncome(const int32 SumOfIncomeVar)
{
	this->SumOfIncome = SumOfIncomeVar;
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
