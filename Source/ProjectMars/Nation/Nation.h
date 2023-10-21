// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Nation.generated.h"

class UEconomyManager;

UCLASS()
class PROJECTMARS_API UNation : public UObject
{
	GENERATED_BODY()

public:
	UNation();

	UFUNCTION()
	UEconomyManager* GetEconomyManager() const;
	
	UFUNCTION()
	UNation* SetEconomyManager(UEconomyManager* EconomyManager);

private:
	UPROPERTY()
	UEconomyManager* EconomyManager;

	/*UPROPERTY()
	UTradeManager* TradeManager;*/

	/*UPROPERTY()
	UArmyManager* ArmyManager;*/
	
};
