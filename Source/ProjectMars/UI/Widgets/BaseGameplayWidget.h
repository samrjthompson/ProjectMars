// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseGameplayWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UBaseGameplayWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UBaseGameplayWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;
	
};
