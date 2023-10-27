// Fill out your copyright notice in the Description page of Project Settings.


#include "DevInfoWidget.h"

#include "Components/TextBlock.h"

UDevInfoWidget::UDevInfoWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	TurnNumberText = NewObject<UTextBlock>();
	SeasonText = NewObject<UTextBlock>();
	YearText = NewObject<UTextBlock>();
	CurrentTurnOwnerText = NewObject<UTextBlock>();
}

void UDevInfoWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UDevInfoWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}
