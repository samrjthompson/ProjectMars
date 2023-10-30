// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "FactionButton.generated.h"

class UDelegateController;
class UChooseFactionWidget;

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UFactionButton : public UButton
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void InitialisePointers(UChooseFactionWidget* ChooseFactionWidget);
	
	UFUNCTION()
	void SubscribeToEvents(UDelegateController* DelegateControllerVar);

	UFUNCTION()
	void OnHoveredPassSelf();

	UFUNCTION()
	void OnhoveredRemove();

private:
	UPROPERTY()
	UChooseFactionWidget* ParentWidget{ nullptr };
	
};
