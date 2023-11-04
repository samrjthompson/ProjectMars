// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameWidget.h"

#include "Components/Button.h"
#include "Construction/ConstructionButtonWidget.h"
#include "Construction/ConstructionWidget.h"

UMainGameWidget::UMainGameWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bIsConstructionOpen = false;
}

void UMainGameWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UMainGameWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMainGameWidget::PostInitProperties()
{
	Super::PostInitProperties();
}

void UMainGameWidget::ShowConstruction()
{
	if (bIsConstructionOpen)
	{
		this->ConstructionWidget->SetVisibility(ESlateVisibility::Hidden);
		bIsConstructionOpen = false;
	} else
	{
		this->ConstructionWidget->SetVisibility(ESlateVisibility::Visible);
		bIsConstructionOpen = true;
	}
}

void UMainGameWidget::InitialiseEvents()
{
	this->ConstructionButtonWidget->AddToViewport();
	this->ConstructionWidget->AddToViewport();
	this->ConstructionWidget->SetVisibility(ESlateVisibility::Hidden);
	
	this->ConstructionButtonWidget->MainButton->OnClicked.AddDynamic(this, &UMainGameWidget::ShowConstruction);
}
