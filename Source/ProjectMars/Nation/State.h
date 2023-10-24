// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "State.generated.h"

class UEconomyManager;

UCLASS()
class PROJECTMARS_API UState : public UObject
{
	GENERATED_BODY()

public:
	UState();

	UFUNCTION()
	UEconomyManager* GetEconomyManager() const;
	
	UFUNCTION()
	UState* SetEconomyManager(UEconomyManager* EconomyManager);

private:
	UPROPERTY()
	UEconomyManager* EconomyManager;

	/*UPROPERTY()
	UTradeManager* TradeManager;*/

	/*UPROPERTY()
	UArmyManager* ArmyManager;*/
	
};
