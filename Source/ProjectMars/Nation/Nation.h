// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Nation.generated.h"

class UDelegateController;
class AProjectMarsPlayer;
class UNationService;

// A class to represent a state such as the Roman Republic or Carthage
UCLASS()
class PROJECTMARS_API UNation : public UObject
{
	GENERATED_BODY()

public:
	explicit UNation(const FObjectInitializer& ObjectInitializer);

	// Functions
	UFUNCTION()
	void SubscribeToEvents(UDelegateController* DelegateControllerVar);

	UFUNCTION()
	void UpdateIncome(const int32 TurnNumberVar);
	
	UFUNCTION()
	UNation* SetFactionTag(const FString& FactionTagVar);

	UFUNCTION()
	const FString& GetFactionTag() const;

	// Getters
	UFUNCTION()
	UNationService* GetNationService() const;
	
	UFUNCTION()
	AProjectMarsPlayer* GetOwningPlayer() const;
	
	// Setters
	UFUNCTION()
	UNation* SetOwningPlayer(AProjectMarsPlayer* PlayerVar);

private:
	// Functions

	
	// Variables
	UPROPERTY(EditAnywhere)
	FString FactionTag;

	UPROPERTY(EditAnywhere)
	AProjectMarsPlayer* OwningPlayer{ nullptr };
	
	UPROPERTY()
	UNationService* NationService{ nullptr };


	/*UPROPERTY()
	UTradeManager* TradeManager;*/

	/*UPROPERTY()
	UArmyManager* ArmyManager;*/
	
};
