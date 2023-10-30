// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TaxData.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UTaxData : public UObject
{
	GENERATED_BODY()

public:
	// Getter
	UFUNCTION()
	float GetTaxRate() const;

	UFUNCTION()
	int32 GetTotalTaxIncome() const;

	UFUNCTION()
	int32 GetBaseTaxValue() const;

	// Setter
	UFUNCTION()
	UTaxData* SetTaxRate(const float TaxRateVar);

	UFUNCTION()
	UTaxData* SetTotalTaxIncome(const int32 TotalTaxIncomeVar);

	UFUNCTION()
	UTaxData* SetBaseTaxValue(const int32 BaseTaxValueVar);

private:
	float TaxRate;
	int32 TotalTaxIncome;
	int32 BaseTaxValue;
};
