// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Factions/FactionBase.h"

float FFactionEconomics::GetNetIncome()
{
	NetIncome = GetGrossIncome() - GetTotalOutgoings();
	
	return FMath::RoundHalfToZero(100 * NetIncome) / 100;
}

float FFactionEconomics::GetGrossIncome()
{
	GrossIncome += TaxIncome;
	GrossIncome += TotalValueOfExports;
	GrossIncome += TotalValueOfImports;
	GrossIncome += LootingIncome;
	GrossIncome += TributeIncome;
	
	return FMath::RoundHalfToZero(100 * GrossIncome) / 100;
}

float FFactionEconomics::GetTotalOutgoings()
{
	Expenses += Wages;
	Expenses += ArmyMaintenance;
	Expenses += FleetMaintenance;
	Expenses += StateMaintenance;
	Expenses += FortMaintenance;
	Expenses += OutgoingTributes;
	
	return FMath::RoundHalfToZero(100 * Expenses) / 100;
}

UFactionBase::UFactionBase()
{

}

FBaseFactionData& UFactionBase::GetRefToFactionData()
{
	return BaseFactionData;
}

FFactionEconomics& UFactionBase::GetRefToEconomicsData()
{
	return FactionEconomics;
}
