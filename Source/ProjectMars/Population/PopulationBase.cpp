// Fill out your copyright notice in the Description page of Project Settings.


#include "PopulationBase.h"


APopulationBase::APopulationBase()
{
	
}

FPopulation::FPopulation()
{
	TotalPopulation = FMath::Clamp(TotalPopulation, 0, 50000000);
	TotalPatricianPop = FMath::Clamp(TotalPatricianPop, 0, 50000000);
	TotalPlebesPop = FMath::Clamp(TotalPlebesPop, 0, 50000000);
	TotalProletariatPop = FMath::Clamp(TotalProletariatPop, 0, 50000000);
	TotalForeignerPop = FMath::Clamp(TotalForeignerPop, 0, 50000000);
	TotalSlavePopulation = FMath::Clamp(TotalSlavePopulation, 0, 50000000);

	PatricianGrowth = 1.005;
	PlebesGrowth = 1.005;
	ProletariatGrowth = 1.005;
	ForeignerGrowth = 1.005;
	SlaveGrowth = 1.005;
}

void FPopulation::UpdateGrowthPerMonth()
{
	PatricianGrowth;
	PlebesGrowth;
	ProletariatGrowth;
	ForeignerGrowth;
	SlaveGrowth;
}

void FPopulation::UpdateMonthlyPopulation()
{
	UE_LOG(LogTemp, Warning, TEXT("Pre-Population: %d"), TotalPopulation);

	TotalPatricianPop *= PatricianGrowth;
	TotalPlebesPop *= PlebesGrowth;
	TotalProletariatPop *= ProletariatGrowth;
	TotalForeignerPop *= ForeignerGrowth;
	TotalSlavePopulation *= SlaveGrowth;

	TotalPopulation =

		TotalPatricianPop +
		TotalPlebesPop +
		TotalProletariatPop +
		TotalForeignerPop +
		TotalSlavePopulation;

	UE_LOG(LogTemp, Warning, TEXT("Post-Population: %d"), TotalPopulation);
}