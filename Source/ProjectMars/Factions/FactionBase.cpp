// Fill out your copyright notice in the Description page of Project Settings.


#include "FactionBase.h"


AFactionBase::AFactionBase()
{
	FactionName = "NONE";
}

void AFactionBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFactionBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

FFaction& AFactionBase::GetRefToFactionData()
{
	return BaseFactionData;
}


FFactionEconomics& AFactionBase::GetRefToEconomicsData()
{
	return FactionEconomics;
}

FPopulation& AFactionBase::GetRefToPopulationData()
{
	return Population;
}

FCultureGroup& AFactionBase::GetRefToCultureGroup()
{
	return CultureGroupObj;
}

FCultureData& AFactionBase::GetRefToCultureData()
{
	return CultureDataObj;
}

void FFactionEconomics::ApplyNetIncomeToTreasury()
{
	Treasury += GetNetIncome();
	if(Treasury < 0)
	{
		bHasADeficit = true;
	}
	else
	{
		bHasADeficit = false;
	}
}
