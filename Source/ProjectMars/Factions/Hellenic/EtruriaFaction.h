// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectMars/Factions/FactionBase.h"
#include "EtruriaFaction.generated.h"

// struct FFaction;
struct FFactionEconomics;

UCLASS()
class PROJECTMARS_API AEtruriaFaction : public AFactionBase
{
	GENERATED_BODY()

public:
	AEtruriaFaction();

	virtual FName GetFactionName() const override { return FactionName; }
	
	// FFaction EtruriaFactionData;	
	FFactionEconomics EtruriaFactionEconomics;
	FPopulation EtruriaPopulation;

protected:
	//virtual FFaction& GetRefToFactionData() override;
	virtual FFactionEconomics& GetRefToEconomicsData() override;
	virtual FPopulation& GetRefToPopulationData() override;
};