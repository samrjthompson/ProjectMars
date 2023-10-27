// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectMars/Framework/CustomObject.h"
#include "UObject/NoExportTypes.h"
#include "Nation.generated.h"

class UEconomyController;
class UDelegateController;
class AProjectMarsPlayer;

// A class to represent a state such as the Roman Republic or Carthage
UCLASS()
class PROJECTMARS_API UNation : public UCustomObject
{
	GENERATED_BODY()

public:
	UNation();

	// Functions
	UFUNCTION()
	UNation* SetFactionTag(const FString& FactionTagVar);

	UFUNCTION()
	const FString& GetFactionTag() const;

	// Getters
	UFUNCTION()
	UEconomyController* GetEconomyController() const;

	UFUNCTION()
	AProjectMarsPlayer* GetOwningPlayer() const;
	
	// Setters
	UFUNCTION()
	UNation* SetEconomyController(UEconomyController* EconomyController);

	UFUNCTION()
	UNation* SetOwningPlayer(AProjectMarsPlayer* PlayerVar);

private:
	// Functions

	
	// Variables
	UPROPERTY(EditAnywhere)
	UEconomyController* EconomyController;

	UPROPERTY(EditAnywhere)
	class UNationDelegateController* NationDelegateController;

	UPROPERTY(EditAnywhere)
	FString FactionTag;

	UPROPERTY(EditAnywhere)
	AProjectMarsPlayer* OwningPlayer{ nullptr };

	/*UPROPERTY()
	UTradeManager* TradeManager;*/

	/*UPROPERTY()
	UArmyManager* ArmyManager;*/
	
};
