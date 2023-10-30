// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseFactionWidget.h"

#include "FactionInfoWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Button.h"
#include "Components/SizeBox.h"
#include "Components/SizeBoxSlot.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "WidgetComponents/FactionButton.h"

UChooseFactionWidget::UChooseFactionWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

void UChooseFactionWidget::NativeConstruct()
{
	Super::NativeConstruct();


	/*FactionButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("FactionButton"));
	RootWidget->AddChild(FactionButton);

	FactionButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("FactionButton2"));
	RootWidget->AddChild(FactionButton);*/
}

void UChooseFactionWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UChooseFactionWidget::SubscribeToEvents(UDelegateController* DelegateControllerVar)
{

}

void UChooseFactionWidget::ShowFactionInfoWidget(UFactionButton* ButtonHovered)
{
	ensure(ButtonHovered);

	FactionInfoWidget->SetFactionInfo(ButtonHovered->GetName());
	
	FactionInfoWidget->SetVisibility(ESlateVisibility::Visible);
}

void UChooseFactionWidget::InitialiseFactionButtonsWithSelf()
{
	FactionInfoWidget->AddToViewport();
	FactionInfoWidget->SetVisibility(ESlateVisibility::Hidden);
	FactionButton_Rome->InitialisePointers(this);
	FactionButton_Carthage->InitialisePointers(this);
	FactionButton_Samnium->InitialisePointers(this);
}

void UChooseFactionWidget::BuildWidgets()
{
	// THIS IS FOR FUTURE REFERENCE -- How to create widgets dynamically in C++
	// See:
	// https://forums.unrealengine.com/t/create-widget-in-pure-c/367306/2
	// https://forums.unrealengine.com/t/c-create-widget/298562/3
	// https://forums.unrealengine.com/t/c-widget-how-can-i-access-the-slots-padding-instead-of-the-contents-padding/271021

	
	// UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());
	// RootWidget->AddChild(NewFactionButton);
	/*for (int i = 0; i < 4; i++)
	{
		UButton* NewFactionButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
		VerticalBoxMain->AddChild(NewFactionButton);
		UVerticalBoxSlot* VBSlot = CastChecked<UVerticalBoxSlot>(VerticalBoxMain->GetSlots()[i + 1]);
		VBSlot->SetPadding(10);

		ListOfButtons.Add(NewFactionButton);
	}*/
	/*UButton* Button1 = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
	RootWidget->AddChild(Button1);
	UButton* Button2 = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass());
	RootWidget->AddChild(Button2);*/
	//ListOfButtons.Add(FactionButton2);
}
