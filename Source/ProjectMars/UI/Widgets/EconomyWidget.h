// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EconomyWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UEconomyWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UEconomyWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

};