// Fill out your copyright notice in the Description page of Project Settings.


#include "RomeFaction.h"

#include "ProjectMars/Cultures/Italic/ItalicCultureGroup.h"

ARomeFaction::ARomeFaction()
{
	// FBaseFactionData Setup
	RomeFactionData.FactionName = "Roman Republic";

	// Initialise Variables
	FactionName = RomeFactionData.FactionName;

	this->FactionType = EFaction::Rome;
	this->CultureGroup = ECultureGroup::Italic;
	this->Culture = ECultureName::Roman;
	
	// Population
	this->RomePopulation.TotalPatricianPop = 2000;
	this->RomePopulation.TotalPlebesPop = 10000;
	this->RomePopulation.TotalProletariatPop = 30000;
	this->RomePopulation.TotalForeignerPop = 200;
	this->RomePopulation.TotalSlavePopulation = 8000;

	// TODO: ECONOMY : Implement systems so economy values are not hard-coded
	// ECONOMY // These are placeholder values to test out the functionality of economy
	
	// Income
	//this->RomeFactionEconomy.TaxIncome = 24.6f;
	this->RomeFactionEconomy.TotalValueOfExports = 68.2f;
	this->RomeFactionEconomy.TotalValueOfImports = 34.2f;
	this->RomeFactionEconomy.LootingIncome = 0.f;
	this->RomeFactionEconomy.TributeIncome = 3.4f;

	// Outgoings
	this->RomeFactionEconomy.ArmyMaintenance = 134.4f;
	this->RomeFactionEconomy.FleetMaintenance = 78.7f;
	this->RomeFactionEconomy.FortMaintenance = 4.7f;
	this->RomeFactionEconomy.StateMaintenance = 25.6f;
	this->RomeFactionEconomy.Wages = 56.f;
	this->RomeFactionEconomy.OutgoingTributes = 0.f;	
}

FBaseFactionData& ARomeFaction::GetRefToFactionData()
{
	Super::GetRefToFactionData();

	return RomeFactionData;
}

FFactionEconomics& ARomeFaction::GetRefToEconomicsData()
{
	Super::GetRefToEconomicsData();

	return RomeFactionEconomy;
}

FPopulation& ARomeFaction::GetRefToPopulationData()
{
	Super::GetRefToPopulationData();

	return RomePopulation;
}

FCultureData& ARomeFaction::GetRefToCultureData()
{
	Super::GetRefToCultureData();

	return RomanCultureData;
}