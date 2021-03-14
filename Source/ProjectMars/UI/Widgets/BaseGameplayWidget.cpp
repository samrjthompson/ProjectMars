// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameplayWidget.h"

#include "Components/TextBlock.h"

UBaseGameplayWidget::UBaseGameplayWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

void UBaseGameplayWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
}

void UBaseGameplayWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

}

void UBaseGameplayWidget::ShowTooltip(UUserWidget* Widget)
{
	SetToolTip(Widget);
	Widget->SetVisibility(ESlateVisibility::Hidden);
	
	if (EconomyText->IsHovered())
	{
		Widget->SetVisibility(ESlateVisibility::Visible);
	}
}
