// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Nation/State.h"

#include "ProjectMars/Economy/EconomyController.h"

UState::UState()
{
	// Constructor
	EconomyController = NewObject<UEconomyController>();
}

UEconomyController* UState::GetEconomyController() const
{
	return EconomyController;
}

UState* UState::SetEconomyController(UEconomyController* EconomyControllerVar)
{
	this->EconomyController = EconomyControllerVar;
	return this;
}
