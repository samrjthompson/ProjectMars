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

	NobleGrowth = 1.005;
	CitizenGrowth = 1.005;
	FreemanGrowth = 1.005;
	TribesmanGrowth = 1.005;
	SlaveGrowth = 1.005;
}

void FPopulation::UpdateGrowthPerMonth()
{
	NobleGrowth;
	CitizenGrowth;
	FreemanGrowth;
	TribesmanGrowth;
	SlaveGrowth;
}

void FPopulation::UpdateMonthlyPopulation()
{
	UE_LOG(LogTemp, Warning, TEXT("Pre-Population: %d"), TotalPopulation);

	TotalPlebesPop *= NobleGrowth;
	TotalPlebesPop *= CitizenGrowth;
	TotalProletariatPop *= FreemanGrowth;
	TotalForeignerPop *= TribesmanGrowth;
	TotalSlavePopulation *= SlaveGrowth;

	TotalPopulation =

		TotalPatricianPop +
		TotalPlebesPop +
		TotalProletariatPop +
		TotalForeignerPop +
		TotalSlavePopulation;

	UE_LOG(LogTemp, Warning, TEXT("Post-Population: %d"), TotalPopulation);
}