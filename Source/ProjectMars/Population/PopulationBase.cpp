// Fill out your copyright notice in the Description page of Project Settings.


#include "PopulationBase.h"


APopulationBase::APopulationBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APopulationBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("begin play"));
}

FPopulation::FPopulation()
{
	TotalPopulation = FMath::Clamp(TotalPopulation, 0, 50000000);
	TotalUpperClassPop = FMath::Clamp(TotalUpperClassPop, 0, 50000000);
	TotalMiddleClassPop = FMath::Clamp(TotalMiddleClassPop, 0, 50000000);
	TotalLowerClassPop = FMath::Clamp(TotalLowerClassPop, 0, 50000000);
	TotalSlavePopulation = FMath::Clamp(TotalSlavePopulation, 0, 50000000);

	UpperClassGrowth = 1.005;
	MiddleClassGrowth = 1.005;
	LowerClassGrowth = 1.005;
	ForeignerGrowth = 1.005;
	SlaveGrowth = 1.005;

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
	UE_LOG(LogTemp, Warning, TEXT("Pre-Population: %d"), TotalPopulation);

	TotalUpperClassPop *= UpperClassGrowth;
	TotalMiddleClassPop *= MiddleClassGrowth;
	TotalLowerClassPop *= LowerClassGrowth;
	TotalSlavePopulation *= SlaveGrowth;

	TotalPopulation =

		TotalUpperClassPop +
		TotalMiddleClassPop +
		TotalLowerClassPop +
		TotalSlavePopulation;

	UE_LOG(LogTemp, Warning, TEXT("Post-Population: %d"), TotalPopulation);
}