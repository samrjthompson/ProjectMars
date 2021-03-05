// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Factions/Hellenic/RomeFaction.h"

#include "ProjectMars/Cultures/CultureBase.h"
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
}

void URomeFaction::UpdateCurrentIncome()
{
	Super::UpdateCurrentIncome();

	UE_LOG(LogTemp, Warning, TEXT("ROMAN MONEYYYYY!"));
}

FBaseFactionData URomeFaction::GetRefToFactionData()
{
	Super::GetRefToFactionData();

	return RomeFactionData;
}
