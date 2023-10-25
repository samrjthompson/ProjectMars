// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StateBuilder.generated.h"

class UState;

/**
 * This class is responsible for building all states in the game when the game starts.
 * There should only be one instance of this class per game.
 */
UCLASS()
class PROJECTMARS_API UStateBuilder : public UObject
{
	GENERATED_BODY()

public:
	UStateBuilder();
	
	UFUNCTION()
	const TMap<FString, UState*>& BuildStates();

	UFUNCTION()
	const TMap<FString, UState*>& AddState(FString StateName, UState* State);

	// Getters
	UFUNCTION()
	const TMap<FString, UState*>& GetStates() const;

	// Setters

private:
	UPROPERTY()
	TMap<FString, UState*> States;
};
