// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectMars/Framework/CustomObject.h"
#include "UObject/NoExportTypes.h"
#include "Nation.generated.h"

class UEconomyController;
class UDelegateController;

// A class to represent a state such as the Roman Republic or Carthage
UCLASS()
class PROJECTMARS_API UNation : public UCustomObject
{
	GENERATED_BODY()

public:
	UNation();
	
	virtual void OnMonthlyUpdate() override;

	// Getters
	UFUNCTION()
	UEconomyController* GetEconomyController() const;
	
	// Setters
	UFUNCTION()
	UNation* SetEconomyController(UEconomyController* EconomyController);

private:
	// Functions

	
	// Variables
	UPROPERTY()
	UEconomyController* EconomyController;

	UPROPERTY()
	class UNationDelegateController* NationDelegateController;

	/*UPROPERTY()
	UTradeManager* TradeManager;*/

	/*UPROPERTY()
	UArmyManager* ArmyManager;*/
	
};
