// Fill out your copyright notice in the Description page of Project Settings.


#include "IncomeSource.h"

FIncomeSource::FIncomeSource()
{
}

int32 FIncomeSource::GetIncome() const
{
	return Income;
}

FIncomeSource* FIncomeSource::SetIncome(int32 IncomeVar)
{
	this->Income = IncomeVar;
	return this;
}

int32 FIncomeSource::UpdateIncome(int32 IncomeToAdd)
{
	return Income += IncomeToAdd;
}
