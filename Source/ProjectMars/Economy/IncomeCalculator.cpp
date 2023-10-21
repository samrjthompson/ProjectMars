// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Economy/IncomeCalculator.h"

int32 UIncomeCalculator::CalculateGrossIncome(const TMap<EIncomeSourceType, int32>& MapOfIncomeSourcesVar) const
{
	int32 TotalIncome{ 0 };
	for (const auto IncomeSource : MapOfIncomeSourcesVar)
	{
		TotalIncome += IncomeSource.Value;
	}
	return TotalIncome;
}

int32 UIncomeCalculator::CalculateNetIncome(const int32 GrossIncome, const int32 GrossOutgoings) const
{
	return GrossIncome - GrossOutgoings;
}
