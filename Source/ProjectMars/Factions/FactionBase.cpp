// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Factions/FactionBase.h"

UFactionBase::UFactionBase()
{

}

void UFactionBase::UpdateCurrentIncome()
{
	// Write modifiers for income
	CurrentFactionGrossIncome += BaseFactionData.TaxIncome;
	CurrentFactionGrossIncome += BaseFactionData.TotalValueOfExports;
	CurrentFactionGrossIncome += BaseFactionData.TotalValueOfImports;
	CurrentFactionGrossIncome += BaseFactionData.LootingIncome;
	CurrentFactionGrossIncome += BaseFactionData.TributeIncome;

	CurrentFactionExpenses += BaseFactionData.Wages;
	CurrentFactionExpenses += BaseFactionData.ArmyMaintenance;
	CurrentFactionExpenses += BaseFactionData.FleetMaintenance;
	CurrentFactionExpenses += BaseFactionData.StateMaintenance;
	CurrentFactionExpenses += BaseFactionData.FortMaintenance;
	CurrentFactionExpenses += BaseFactionData.OutgoingTributes;

	CurrentFactionNetIncome = CurrentFactionGrossIncome - CurrentFactionExpenses;

	// Rounding to 2 decimal places with RoundHalfToZero function
	BaseFactionData.Expenses = FMath::RoundHalfToZero(100 * CurrentFactionExpenses) / 100;
	BaseFactionData.GrossIncome = FMath::RoundHalfToZero(100 * CurrentFactionGrossIncome) / 100;
	BaseFactionData.NetIncome = FMath::RoundHalfToZero(100 * CurrentFactionNetIncome) / 100;

	UE_LOG(LogTemp, Warning, TEXT("OutgoingTributes: %f"), FMath::RoundHalfToZero(100 * BaseFactionData.OutgoingTributes) / 100);
}

FBaseFactionData UFactionBase::GetRefToFactionData()
{
	return BaseFactionData;
}
