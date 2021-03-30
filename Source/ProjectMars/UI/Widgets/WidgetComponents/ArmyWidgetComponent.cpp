// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmyWidgetComponent.h"
#include "Components/WidgetComponent.h"
#include "ProjectMars/UI/Widgets/Military/ArmyRoster.h"

UArmyWidgetComponent::UArmyWidgetComponent()
{
	SetComponentTickEnabled(false);
	
	Space = EWidgetSpace::Screen;

	SetActive(true);

	SetHiddenInGame(true);
}

void UArmyWidgetComponent::RefreshWidget()
{
	ArmyRosterWidget = Cast<UArmyRoster>(GetUserWidgetObject());
	
	if(ArmyRosterWidget)
	{
		ArmyRosterWidget->UpdateArmyRosterWidget(this);
	}
}

void UArmyWidgetComponent::ArmyClicked(AProjectMarsPlayer* PlayerCharacter)
{
	SetHiddenInGame(false);

	RefreshWidget();
	
	OnClick.Broadcast(PlayerCharacter);
}

void UArmyWidgetComponent::ArmyUnClicked(AProjectMarsPlayer* PlayerCharacter)
{
	OnUnClick.Broadcast(PlayerCharacter);

	SetHiddenInGame(true);
}
