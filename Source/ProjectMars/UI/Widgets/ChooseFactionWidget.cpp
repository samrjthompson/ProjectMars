// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/UI/Widgets/ChooseFactionWidget.h"

#include "Components/Button.h"

UChooseFactionWidget::UChooseFactionWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

void UChooseFactionWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
}

void UChooseFactionWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if(RomeButton && EtruriaButton)
	{
		RomeButton->OnClicked.AddDynamic(this, &UChooseFactionWidget::CloseWidget);
		EtruriaButton->OnClicked.AddDynamic(this, &UChooseFactionWidget::CloseWidget);
	}	
}

void UChooseFactionWidget::CloseWidget()
{
	this->RemoveFromParent();
}
