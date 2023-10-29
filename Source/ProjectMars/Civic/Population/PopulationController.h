// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PopulationController.generated.h"

class UPopulationData;

/**
 * Manages population for a nation
 */
UCLASS()
class PROJECTMARS_API UPopulationController : public UObject
{
	GENERATED_BODY()

public:
	explicit UPopulationController(const FObjectInitializer& ObjInitializer);

	// Functions

	// Getters
	const UPopulationData* GetPopulationData() const;
	
	// Setters

private:
	UPROPERTY()
	const UPopulationData* PopulationData{ nullptr };
};

