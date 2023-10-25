// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CustomObject.generated.h"

class UDelegateController;

/**
 * This is a parent class to all the game's custom UObjects and is responsible for replicated functions and variables.
 */
UCLASS()
class PROJECTMARS_API UCustomObject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void SubscribeToDelegateEvents(UDelegateController* DelegateControllerVar);

	UFUNCTION()
	virtual void OnMonthlyUpdate();

private:

protected:
	
};
