// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NationBuilder.generated.h"

class UNation;

/**
 * This class is responsible for building all states in the game when the game starts.
 * There should only be one instance of this class per game.
 */
UCLASS()
class PROJECTMARS_API UNationBuilder : public UObject
{
	GENERATED_BODY()

public:
	UNationBuilder();
	
	UFUNCTION()
	TMap<FString, UNation*>& BuildNations(const TArray<FString>& FactionTagsVar);

	UFUNCTION()
	const TMap<FString, UNation*>& AddNation(const FString& NationNameVar, UNation* NationVar);

	// Getters
	UFUNCTION()
	const TMap<FString, UNation*>& GetNations() const;

	// Setters

private:
	UPROPERTY()
	TMap<FString, UNation*> Nations;
};
