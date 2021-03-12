// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Factions/Hellenic/EtruriaFaction.h"

#include "ProjectMars/Cultures/Italic/ItalicCultureGroup.h"

AEtruriaFaction::AEtruriaFaction()
{
	EtruriaFactionData.FactionName = "Etruria";

	FactionName = EtruriaFactionData.FactionName;

	this->FactionType = EFaction::Etruria;
	this->CultureGroup = ECultureGroup::Italic;
	this->Culture = ECulture::Etruscan;

	// Population
	this->Population.TotalNoblePopulation = 1500;
	this->Population.TotalCitizenPopulation = 8000;
	this->Population.TotalFreemanPopulation = 35000;
	this->Population.TotalTribesmanPopulation = 400;
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
