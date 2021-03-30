// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmyRoster.h"

UArmyRoster::UArmyRoster(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

void UArmyRoster::NativeConstruct()
{
	Super::NativeConstruct();
	
}

void UArmyRoster::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
}

void UArmyRoster::UpdateArmyRosterWidget(UArmyWidgetComponent* Comp)
{
	if(Comp)
	{
		UE_LOG(LogTemp, Warning, TEXT("UpdateArmyRosterWidget CALLED"));
	}
}

void UArmyRoster::DrawToScreen()
{
	this->AddToViewport();
}
