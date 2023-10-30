// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectMars/Civic/Population/PopulationData.h"
#include "ProjectMars/Civic/Population/PopulationService.h"
#include "UObject/Object.h"
#include "TaxService.generated.h"

class UTaxData;

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UTaxService : public UObject
{
	GENERATED_BODY()

public:
	explicit UTaxService(const FObjectInitializer& ObjectInitializer);
	
	// Functions
	void SetTotalTaxIncome(const int32 NewTaxIncomeVar) const;

	int32 GetBaseValueTax() const;

	void SetTaxIncome(const int32 TaxIncomeVar) const;
	
private:
	UPROPERTY()
	UTaxData* TaxData{ nullptr };
	
};
