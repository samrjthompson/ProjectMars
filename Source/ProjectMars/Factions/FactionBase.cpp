// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Factions/FactionBase.h"

FPopulation::FPopulation()
{
	TotalPopulation = FMath::Clamp(TotalPopulation, 0, 50000000);
	TotalNoblePopulation = FMath::Clamp(TotalNoblePopulation, 0, 50000000);
	TotalCitizenPopulation = FMath::Clamp(TotalCitizenPopulation, 0, 50000000);
	TotalFreemanPopulation = FMath::Clamp(TotalFreemanPopulation, 0, 50000000);
	TotalTribesmanPopulation = FMath::Clamp(TotalTribesmanPopulation, 0, 50000000);
	TotalSlavePopulation = FMath::Clamp(TotalSlavePopulation, 0, 50000000);

	/*TotalNoblePopulation = 2000
	TotalCitizenPopulation =
	TotalFreemanPopulation =
	TotalTribesmanPopulation =
	TotalSlavePopulation =*/


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
	// GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Orange, TEXT("Population: %d"), TotalPopulation);
}

float FFactionEconomics::GetNetIncome()
{
	NetIncome = GetGrossIncome() - GetTotalOutgoings();

	// UE_LOG(LogTemp, Warning, TEXT("Net Income: %f"), NetIncome);

	if(NetIncome < 0)
	{
		bHasNegativeIncome = true;
	}
	else
	{
		bHasNegativeIncome = false;
	}

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

void FFactionEconomics::SetTaxIncome()
{
	
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

FPopulation& UFactionBase::GetRefToPopulationData()
{
	return Population;
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
