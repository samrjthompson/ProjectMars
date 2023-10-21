// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IncomeSource.generated.h"

/**
 * The parent class for all Income Sources.
 */
USTRUCT()
struct PROJECTMARS_API FIncomeSource 
{
	GENERATED_BODY()

public:
	FIncomeSource();
	
	// Getters
	int32 GetIncome() const;

	// Setters
	FIncomeSource* SetIncome(int32 IncomeVar);

	int32 UpdateIncome(int32 IncomeToAdd);

protected:
	int32 Income{ 0 };

private:
	
};
