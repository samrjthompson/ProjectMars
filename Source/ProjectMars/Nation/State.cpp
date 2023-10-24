// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Nation/State.h"

#include "ProjectMars/Economy/EconomyManager.h"

UState::UState()
{
	// Constructor
	EconomyManager = NewObject<UEconomyManager>();
}

UEconomyManager* UState::GetEconomyManager() const
{
	return EconomyManager;
}

UState* UState::SetEconomyManager(UEconomyManager* EconomyManagerVar)
{
	this->EconomyManager = EconomyManagerVar;
	return this;
}
