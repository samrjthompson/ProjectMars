// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Nation/Nation.h"

#include "ProjectMars/Economy/EconomyManager.h"

UNation::UNation()
{
	// Constructor
	EconomyManager = NewObject<UEconomyManager>();
}

UEconomyManager* UNation::GetEconomyManager() const
{
	return EconomyManager;
}

UNation* UNation::SetEconomyManager(UEconomyManager* EconomyManagerVar)
{
	this->EconomyManager = EconomyManagerVar;
	return this;
}
