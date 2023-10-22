// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ProductionItem.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UProductionItem : public UObject
{
	GENERATED_BODY()

public:
	UProductionItem();

	void AddModifierToCurrentValue(float ModifierVal);

	// Getters
	int32 GetCurrentValue() const;

	// Setters
	UProductionItem* SetCurrentValue(const int32 NewValue);
	
protected:
	int32 CurrentValue{};
	
};
