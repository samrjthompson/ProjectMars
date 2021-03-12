// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PopulationBase.generated.h"


UENUM()
enum class EPopType
{
	Noble,
	Citizen,
	Freeman,
	Tribesman,
	Slave
};

USTRUCT()
struct FPopulation
{
	GENERATED_BODY()

	FPopulation();

	// General
	int32 TotalPopulation{};
	int32 TotalNoblePopulation{};
	int32 TotalCitizenPopulation{};
	int32 TotalFreemanPopulation{};
	int32 TotalTribesmanPopulation{};
	int32 TotalSlavePopulation{};

	// Growth
	float TotalGrowth{};
	float TotalShrink{};
	float NetGrowth{};

	float NobleGrowth{};
	float CitizenGrowth{};
	float FreemanGrowth{};
	float TribesmanGrowth{};
	float SlaveGrowth{};

	// Updates the grow as a percentage of each pop type
	void UpdateGrowthPerMonth();

	// Updates the total population each month after factoring in the growth that month
	void UpdateMonthlyPopulation();
};

UCLASS()
class PROJECTMARS_API APopulationBase : public AActor
{
	GENERATED_BODY()

	APopulationBase();
	
};