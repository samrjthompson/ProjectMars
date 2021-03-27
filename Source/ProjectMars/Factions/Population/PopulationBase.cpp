// Fill out your copyright notice in the Description page of Project Settings.


#include "PopulationBase.h"


FPopulation::FPopulation()
{
	TotalPopulation = FMath::Clamp(TotalPopulation, 0, 50000000);
	TotalUpperClassPop = FMath::Clamp(TotalUpperClassPop, 0, 50000000);
	TotalMiddleClassPop = FMath::Clamp(TotalMiddleClassPop, 0, 50000000);
	TotalLowerClassPop = FMath::Clamp(TotalLowerClassPop, 0, 50000000);
	TotalSlavePopulation = FMath::Clamp(TotalSlavePopulation, 0, 50000000);

	UpperClassGrowth = 5;
	MiddleClassGrowth = 23;
	LowerClassGrowth = 26;
	SlaveGrowth = 21;

	TotalPopulation =

		TotalUpperClassPop +
		TotalMiddleClassPop +
		TotalLowerClassPop +
		TotalSlavePopulation;
}

void FPopulation::UpdateGrowthPerMonth()
{
	UpperClassGrowth;
	MiddleClassGrowth;
	LowerClassGrowth;
	ForeignerGrowth;
	SlaveGrowth;
}

void FPopulation::UpdateMonthlyPopulation()
{
	TotalUpperClassPop += UpperClassGrowth;
	TotalMiddleClassPop += MiddleClassGrowth;
	TotalLowerClassPop += LowerClassGrowth;
	TotalSlavePopulation += SlaveGrowth;

	TotalPopulation =

		TotalUpperClassPop +
		TotalMiddleClassPop +
		TotalLowerClassPop +
		TotalSlavePopulation;

	Manpower = (TotalMiddleClassPop + TotalLowerClassPop) * 0.25;
}