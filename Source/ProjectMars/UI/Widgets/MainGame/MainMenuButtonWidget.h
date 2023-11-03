// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UMainMenuButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	explicit UMainMenuButtonWidget(const FObjectInitializer& ObjectInitializer);
	
	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;
private:
		
};
