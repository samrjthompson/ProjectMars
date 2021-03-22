// Fill out your copyright notice in the Description page of Project Settings.


#include "Economy.h"

#include "ProjectMars/Population/PopulationBase.h"

FEconomics::FEconomics()
{
	StartingTreasury = 5000;
	Treasury = StartingTreasury;

	bHasADeficit = false;
	bHasNegativeIncome = false;

	NetIncome = 0.f;
	GrossIncome = 0.f;
	Expenses = 0.f;
}

void FEconomics::CalculateClassIncome()
{
	if (!Population) { return; }

	UpperClassIncome = ((Population->TotalUpperClassPop * 0.8) * 0.75);
}

// TODO: Implement tax collection system
void FEconomics::CollectTaxes(struct FPopulation& Obj)
{
	const float UpperClassTax = Obj.TotalUpperClassPop * UpperClassTaxRate;
	const float MiddleClassTax = Obj.TotalMiddleClassPop * MiddleClassTaxRate;
	const float LowerClassTax = Obj.TotalLowerClassPop * LowerClassTaxRate;

	TaxIncome =
		UpperClassTax +
		MiddleClassTax +
		LowerClassTax;
}

float FEconomics::GetNetIncome()
{
	NetIncome = GetGrossIncome() - GetTotalOutgoings();

	// UE_LOG(LogTemp, Warning, TEXT("Net Income: %f"), NetIncome);

	if (NetIncome < 0)
	{
		bHasNegativeIncome = true;
	}
	else
	{
		bHasNegativeIncome = false;
	}

	return FMath::RoundHalfToZero(100 * NetIncome) / 100;
}

float FEconomics::GetGrossIncome()
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

float FEconomics::GetTotalOutgoings()
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

void FEconomics::SetTaxIncome()
{

}