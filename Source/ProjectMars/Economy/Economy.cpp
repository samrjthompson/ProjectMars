// Fill out your copyright notice in the Description page of Project Settings.


#include "Economy.h"

#include "ProjectMars/Population/PopulationBase.h"

void FFactionEconomics::CalculateClassIncome()
{
	if (!Population) { return; }

	PatricianIncome = ((Population->TotalPatricianPop * 0.8) * 0.75);
}

// Sets default values
AEconomy::AEconomy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AEconomy::BeginPlay()
{
	Super::BeginPlay();
	
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
void FFactionEconomics::CollectTaxes(struct FPopulation& Obj)
{
	const float NobleTax = Obj.TotalPatricianPop * PatricianTaxRate;
	const float CitizenTax = Obj.TotalPlebesPop * PlebesTaxRate;
	const float FreemanTax = Obj.TotalProletariatPop * ProletariatTaxRate;
	const float TribesmanTax = Obj.TotalForeignerPop * ForeignerTaxRate;

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