// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomObject.h"

#include "Logging/StructuredLog.h"
#include "ProjectMars/Delegates/DelegateController.h"

void UCustomObject::SubscribeToDelegateEvents(UDelegateController* DelegateControllerVar)
{
	DelegateControllerVar->OnMonthlyUpdate.AddDynamic(this, &UCustomObject::OnMonthlyUpdate);
}

void UCustomObject::OnMonthlyUpdate()
{
	UE_LOGFMT(LogTemp, Warning, "Custom object monthly update");
}
