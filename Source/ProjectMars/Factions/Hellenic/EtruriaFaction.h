// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectMars/Factions/FactionBase.h"
#include "EtruriaFaction.generated.h"

struct FBaseFactionData;
struct FFactionEconomics;

UCLASS()
class PROJECTMARS_API UEtruriaFaction : public UFactionBase
{
	GENERATED_BODY()

public:
	UEtruriaFaction();

	inline FName GetFactionName() const { return FactionName; };
	
	FBaseFactionData EtruriaFactionData;	
	FFactionEconomics EtruriaFactionEconomics;
	FPopulation EtruriaPopulation;

protected:
	virtual FBaseFactionData& GetRefToFactionData() override;
	virtual FFactionEconomics& GetRefToEconomicsData() override;
	virtual FPopulation& GetRefToPopulationData() override;
};