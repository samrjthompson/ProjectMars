// Fill out your copyright notice in the Description page of Project Settings.


#include "Nation.h"

#include "Logging/StructuredLog.h"
#include "ProjectMars/Delegates/StateDelegateController.h"
#include "ProjectMars/Economy/EconomyController.h"

UNation::UNation()
{
	// StateDelegateController
	NationDelegateController = NewObject<UNationDelegateController>();

	// EconomyController
	EconomyController = NewObject<UEconomyController>();
	EconomyController->SubscribeToDelegateEvents(NationDelegateController);
}

UEconomyController* UNation::GetEconomyController() const
{
	return EconomyController;
}

UNation* UNation::SetEconomyController(UEconomyController* EconomyControllerVar)
{
	this->EconomyController = EconomyControllerVar;
	return this;
}

void UNation::OnMonthlyUpdate()
{
	NationDelegateController->OnNationMonthlyUpdate.Broadcast();
	UE_LOGFMT(LogTemp, Display, "State monthly update");
}
