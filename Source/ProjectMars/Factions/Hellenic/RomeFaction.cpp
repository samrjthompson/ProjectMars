// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Factions/Hellenic/RomeFaction.h"

#include "ProjectMars/Cultures/Italic/ItalicCultureGroup.h"

URomeFaction::URomeFaction()
{
	// FBaseFactionData Setup
	RomeFactionData.FactionName = "Roman Republic";

	// Initialise Variables
	FactionName = RomeFactionData.FactionName;

	this->FactionType = EFaction::Rome;
	this->CultureGroup = ECultureGroup::Italic;
	this->Culture = ECulture::Roman;
	
	// Population
	this->RomePopulation.TotalNoblePopulation = 2000;
	this->RomePopulation.TotalCitizenPopulation = 10000;
	this->RomePopulation.TotalFreemanPopulation = 30000;
	this->RomePopulation.TotalTribesmanPopulation = 200;
	this->RomePopulation.TotalSlavePopulation = 8000;

	// Economy
	this->RomeFactionEconomy.TaxIncome = 24.6f;
	this->RomeFactionEconomy.TotalValueOfExports = 68.2f;
	this->RomeFactionEconomy.TotalValueOfImports = 34.2f;
	this->RomeFactionEconomy.LootingIncome = 0.f;
	this->RomeFactionEconomy.TributeIncome = 3.4f;
}

FBaseFactionData& URomeFaction::GetRefToFactionData()
{
	Super::GetRefToFactionData();

	return RomeFactionData;
}

FFactionEconomics& URomeFaction::GetRefToEconomicsData()
{
	Super::GetRefToEconomicsData();

	return RomeFactionEconomy;
}

FPopulation& URomeFaction::GetRefToPopulationData()
{
	Super::GetRefToPopulationData();

	return RomePopulation;
}