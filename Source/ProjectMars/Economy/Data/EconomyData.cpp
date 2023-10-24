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

int32 FEconomyData::GetExpenses() const
{
	return Expenses;
}

FEconomyData* FEconomyData::SetExpenses(const int32 ExpensesVar)
{
	this->Expenses = ExpensesVar;
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