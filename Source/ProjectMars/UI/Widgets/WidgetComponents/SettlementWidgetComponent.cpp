// Fill out your copyright notice in the Description page of Project Settings.


#include "SettlementWidgetComponent.h"
#include "ProjectMars/UI/Widgets/Civic/SettlementCard.h"

USettlementWidgetComponent::USettlementWidgetComponent()
{
	SetComponentTickEnabled(false);

	Space = EWidgetSpace::Screen;

	SetActive(true);

	SetHiddenInGame(false);
}

void USettlementWidgetComponent::RefreshWidget()
{
	SettlementCard = Cast<USettlementCard>(GetUserWidgetObject());

	if (SettlementCard)
	{
		SettlementCard->UpdateArmyRosterWidget(this);
	}
}
