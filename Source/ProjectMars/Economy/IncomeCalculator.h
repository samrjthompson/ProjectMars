// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IncomeCalculator.generated.h"

enum class EIncomeType : uint8;

/**
 * A Util class that helps the EconomyManager perform income calculations
 */
UCLASS()
class PROJECTMARS_API UIncomeCalculator : public UObject
{
	GENERATED_BODY()

public:
	int32 CalculateGrossIncome(const TMap<EIncomeType, int32>& MapOfIncomeSourcesVar) const;
	int32 CalculateNetIncome(const int32 GrossIncome, const int32 GrossOutgoings) const;

private:
	
};
