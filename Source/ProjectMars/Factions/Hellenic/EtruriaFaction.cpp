// Fill out your copyright notice in the Description page of Project Settings.


#include "EtruriaFaction.h"

#include "ProjectMars/Cultures/Italic/ItalicCultureGroup.h"

AEtruriaFaction::AEtruriaFaction()
{
	EtruriaFactionData.FactionName = "Etruria";

	FactionName = EtruriaFactionData.FactionName;

	this->FactionType = EFaction::Etruria;
	this->CultureGroup = ECultureGroup::Italic;
	this->Culture = ECultureName::Etruscan;

	// Population
	this->Population.TotalPatricianPop = 1500;
	this->Population.TotalPlebesPop = 8000;
	this->Population.TotalProletariatPop = 35000;
	this->Population.TotalForeignerPop = 400;
	this->Population.TotalSlavePopulation = 4000;
}

FBaseFactionData& AEtruriaFaction::GetRefToFactionData()
{
	Super::GetRefToFactionData();

	return EtruriaFactionData;
}

FFactionEconomics& AEtruriaFaction::GetRefToEconomicsData()
{
	Super::GetRefToEconomicsData();

	return EtruriaFactionEconomics;
}

FPopulation& AEtruriaFaction::GetRefToPopulationData()
{
	Super::GetRefToPopulationData();

	return EtruriaPopulation;
}
