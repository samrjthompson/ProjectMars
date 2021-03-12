// Fill out your copyright notice in the Description page of Project Settings.


#include "PopulationBase.h"


APopulationBase::APopulationBase()
{
	
}

FPopulation::FPopulation()
{
	TotalPopulation = FMath::Clamp(TotalPopulation, 0, 50000000);
	TotalNoblePopulation = FMath::Clamp(TotalNoblePopulation, 0, 50000000);
	TotalCitizenPopulation = FMath::Clamp(TotalCitizenPopulation, 0, 50000000);
	TotalFreemanPopulation = FMath::Clamp(TotalFreemanPopulation, 0, 50000000);
	TotalTribesmanPopulation = FMath::Clamp(TotalTribesmanPopulation, 0, 50000000);
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

	TotalCitizenPopulation *= NobleGrowth;
	TotalCitizenPopulation *= CitizenGrowth;
	TotalFreemanPopulation *= FreemanGrowth;
	TotalTribesmanPopulation *= TribesmanGrowth;
	TotalSlavePopulation *= SlaveGrowth;

	TotalPopulation =

		TotalNoblePopulation +
		TotalCitizenPopulation +
		TotalFreemanPopulation +
		TotalTribesmanPopulation +
		TotalSlavePopulation;

	UE_LOG(LogTemp, Warning, TEXT("Post-Population: %d"), TotalPopulation);
}