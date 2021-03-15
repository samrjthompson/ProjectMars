// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectMars/Factions/FactionBase.h"
#include "RomeFaction.generated.h"

UCLASS()
class PROJECTMARS_API ARomeFaction : public AFactionBase
{
	GENERATED_BODY()
	
public:
	ARomeFaction();

	virtual FName GetFactionName() const override { return FactionName; }

private:	
	FFaction RomeFactionData;
	FFactionEconomics RomeFactionEconomy;
	FPopulation RomePopulation;
	FCultureData RomanCultureData;

protected:
	virtual FFaction& GetRefToFactionData() override;
	virtual FFactionEconomics& GetRefToEconomicsData() override;
	virtual FPopulation& GetRefToPopulationData() override;
	// virtual FCultureGroup& GetRefToCultureGroup() override;
	virtual FCultureData& GetRefToCultureData() override;
};