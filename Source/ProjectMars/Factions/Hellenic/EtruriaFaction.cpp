// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Factions/Hellenic/EtruriaFaction.h"

#include "ProjectMars/Cultures/CultureBase.h"
#include "ProjectMars/Cultures/Italic/ItalicCultureGroup.h"

UEtruriaFaction::UEtruriaFaction()
{
	EtruriaFactionData.FactionName = "Etruria";

	FactionName = EtruriaFactionData.FactionName;

	this->FactionType = EFaction::Etruria;
	this->CultureGroup = ECultureGroup::Italic;
	this->Culture = ECulture::Etruscan;
}
