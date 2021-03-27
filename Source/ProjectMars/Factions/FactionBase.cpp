// Fill out your copyright notice in the Description page of Project Settings.


#include "FactionBase.h"


FPolitics::FPolitics()
{
	
}

FFaction::FFaction()
{

}

FFaction::FFaction(EFactionName InitFaction)
{
	Faction = InitFaction;
}

AFactionBase::AFactionBase()
{

}

void AFactionBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFactionBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

FEconomics& AFactionBase::GetRefToEconomicsData()
{
	return Faction.Economics;
}

FPopulation& AFactionBase::GetRefToPopulationData()
{
	return Faction.Population;
}

FCultureGroup& AFactionBase::GetRefToCultureGroup()
{
	return Faction.CultureGroup;
}

FCultureData& AFactionBase::GetRefToCultureData()
{
	return Faction.CultureData;
}

void FEconomics::ApplyNetIncomeToTreasury()
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