// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyData.h"

UEconomyData::UEconomyData()
{
	Treasury = 0;
}

int32 UEconomyData::GetTreasury() const
{
	return Treasury;
}

UEconomyData* UEconomyData::SetTreasury(const int32 TreasuryVar)
{
	Treasury = TreasuryVar;
	return this;
}

int32 UEconomyData::GetExpenses() const
{
	return Expenses;
}

UEconomyData* UEconomyData::SetExpenses(const int32 ExpensesVar)
{
	this->Expenses = ExpensesVar;
	return this;
}

int32 UEconomyData::GetSumOfIncome() const
{
	return GrossIncome;
}

UEconomyData* UEconomyData::SetGrossIncome(const int32 GrossIncomeVar)
{
	this->GrossIncome = GrossIncomeVar;
	return this;
}

int32 UEconomyData::GetNetIncome() const
{
	return NetIncome;
}

UEconomyData* UEconomyData::SetNetIncome(const int32 NetIncomeVar)
{
	this->NetIncome = NetIncomeVar;
	return this;
}
