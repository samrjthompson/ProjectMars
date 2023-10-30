// Fill out your copyright notice in the Description page of Project Settings.


#include "FactionButton.h"

#include "ProjectMars/UI/Widgets/ChooseFactionWidget.h"
#include "ProjectMars/UI/Widgets/FactionInfoWidget.h"

void UFactionButton::InitialisePointers(UChooseFactionWidget* ChooseFactionWidget)
{
	ParentWidget = ChooseFactionWidget;
	SubscribeToEvents(nullptr);
}

void UFactionButton::OnHoveredPassSelf()
{
	ParentWidget->ShowFactionInfoWidget(this);
}

void UFactionButton::OnhoveredRemove()
{
	ParentWidget->FactionInfoWidget->SetVisibility(ESlateVisibility::Hidden);
}

void UFactionButton::SubscribeToEvents(UDelegateController* DelegateControllerVar)
{
	this->OnHovered.AddDynamic(this, &UFactionButton::OnHoveredPassSelf);
	this->OnUnhovered.AddDynamic(this, &UFactionButton::OnhoveredRemove);
}
