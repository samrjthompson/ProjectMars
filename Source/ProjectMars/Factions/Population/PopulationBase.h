// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PopulationBase.generated.h"


UENUM()
enum class EPopType
{
	UpperClass,
	MiddleClass,
	LowerClass,
	Foreigner,
	Slave
};

USTRUCT()
struct FPopulation
{
	GENERATED_BODY()

	FPopulation();

	// Total patrician population should start at around 10% of the total population of a country/city state
	// Slaves: start low - but, for example, average level of slaves in rome during the empire would be about 30% of total pop
	// https://en.wikipedia.org/wiki/Demography_of_the_Roman_Empire#Population

	// General
	int32 TotalPopulation{};
	int32 TotalUpperClassPop{};
	int32 TotalMiddleClassPop{};
	int32 TotalLowerClassPop{};
	int32 TotalSlavePopulation{};

	// Growth
	float TotalGrowth{};
	float TotalShrink{};
	float NetGrowth{};

	float UpperClassGrowth{};
	float MiddleClassGrowth{};
	float LowerClassGrowth{};
	float ForeignerGrowth{};
	float SlaveGrowth{};

	int32 Manpower{};

	// Updates the grow as a percentage of each pop type
	void UpdateGrowthPerMonth();

	// Updates the total population each month after factoring in the growth that month
	void UpdateMonthlyPopulation();
};