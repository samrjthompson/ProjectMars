// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "State.generated.h"

class UEconomyController;
class UDelegateController;

// A class to represent a state such as the Roman Republic or Carthage
UCLASS()
class PROJECTMARS_API UState : public UObject
{
	GENERATED_BODY()

public:
	UState();

	UFUNCTION()
	void SetupDelegateEvents(UDelegateController* DelegateControllerVar);

	UFUNCTION()
	void OnMonthlyUpdate();

	// Getters
	UFUNCTION()
	UEconomyController* GetEconomyController() const;
	
	// Setters
	UFUNCTION()
	UState* SetEconomyController(UEconomyController* EconomyController);

private:
	// Functions

	
	// Variables
	UPROPERTY()
	UEconomyController* EconomyController;

	UPROPERTY()
	class UStateDelegateController* StateDelegateController;

	/*UPROPERTY()
	UTradeManager* TradeManager;*/

	/*UPROPERTY()
	UArmyManager* ArmyManager;*/
	
};
