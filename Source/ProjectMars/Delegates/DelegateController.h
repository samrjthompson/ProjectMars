// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DelegateController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMonthlyUpdate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerInitialisation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAIFactionInitialisation);

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UDelegateController : public UObject
{
	GENERATED_BODY()
	
public:
	FOnMonthlyUpdate OnMonthlyUpdate;
	FOnPlayerInitialisation OnPlayerInitialisation;
	FOnAIFactionInitialisation OnAIFactionInitialisation;

private:
	
};
