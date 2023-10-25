// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Nation/State.h"

#include "Logging/StructuredLog.h"
#include "ProjectMars/Delegates/StateDelegateController.h"
#include "ProjectMars/Economy/EconomyController.h"

UState::UState()
{
	// StateDelegateController
	StateDelegateController = NewObject<UStateDelegateController>();

	// EconomyController
	EconomyController = NewObject<UEconomyController>();
	EconomyController->SubscribeToDelegateEvents(StateDelegateController);
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

void UState::OnMonthlyUpdate()
{
	StateDelegateController->OnStateMonthlyUpdate.Broadcast();
	UE_LOGFMT(LogTemp, Display, "State monthly update");
}
