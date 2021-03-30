// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ArmyRoster.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UArmyRoster : public UUserWidget
{
	GENERATED_BODY()

public:
	UArmyRoster(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;
};
