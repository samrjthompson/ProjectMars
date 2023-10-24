// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "State.generated.h"

class UEconomyController;

// A class to represent a state such as the Roman Republic or Carthage
UCLASS()
class PROJECTMARS_API UState : public UObject
{
	GENERATED_BODY()

public:
	UState();

	UFUNCTION()
	UEconomyController* GetEconomyController() const;
	
	UFUNCTION()
	UState* SetEconomyController(UEconomyController* EconomyController);

private:
	UPROPERTY()
	UEconomyController* EconomyController;

	/*UPROPERTY()
	UTradeManager* TradeManager;*/

	/*UPROPERTY()
	UArmyManager* ArmyManager;*/
	
};
