// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DelegateController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMonthlyUpdate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerInitialisation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAIFactionInitialisation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndTurn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeTurnOwner, const FString&, CurrentTurnOwner);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStartNewTurn, const int32, TurnNumber);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFirstTurn);

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
	FOnEndTurn OnEndTurn;
	FOnStartNewTurn OnStartNewTurn;
	FOnChangeTurnOwner OnChangeTurnOwner;
	FOnFirstTurn OnFirstTurn;

private:
	
};
