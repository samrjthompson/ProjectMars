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
}

FFactionEconomics::FFactionEconomics()
{
	StartingTreasury = 5000;
	Treasury = StartingTreasury;

	bHasADeficit = false;
	bHasNegativeIncome = false;

	NetIncome = 0.f;
	GrossIncome = 0.f;
	Expenses = 0.f;
}

// TODO: Implement tax collection system
void FFactionEconomics::CollectTaxes(FPopulation& Obj)
{
	const float NobleTax = Obj.TotalNoblePopulation * NobleTaxRate;
	const float CitizenTax = Obj.TotalCitizenPopulation * CitizenTaxRate;
	const float FreemanTax = Obj.TotalFreemanPopulation * FreemanTaxRate;
	const float TribesmanTax = Obj.TotalTribesmanPopulation * TribesmanTaxRate;

	TaxIncome =
		NobleTax +
		CitizenTax +
		FreemanTax +
		TribesmanTax;
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
	/* Because the gross income changes and is unique to the month in which it is affecting the treasury, we want
	 * to reset the gross income to 0 each month and then update it again. Otherwise, GrossIncome will be added
	 * on top of itself each month and affect net income accordingly. */
	
	GrossIncome = 0.f;
	
	GrossIncome += TaxIncome;
	GrossIncome += TotalValueOfExports;
	GrossIncome += TotalValueOfImports;
	GrossIncome += LootingIncome;
	GrossIncome += TributeIncome;
	
	return FMath::RoundHalfToZero(100 * GrossIncome) / 100;
}

float FFactionEconomics::GetTotalOutgoings()
{
	Expenses = 0.f;
	
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
