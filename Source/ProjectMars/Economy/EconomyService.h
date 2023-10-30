// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EconomyService.generated.h"

class UEconomyData;
class UTaxService;
class UFinanceCalculator;

UENUM()
enum class EIncomeType : uint8
{
	Tax,
	Trade,
	Production,
	Loot,
	Slaves,

	Max UMETA(Hidden)
};
ENUM_RANGE_BY_COUNT(EIncomeType, EIncomeType::Max);

UENUM()
enum class EExpenseType : uint8
{
	Army,
	Navy,
	Tribute,
	Corruption,

	Max UMETA(Hidden)
};
ENUM_RANGE_BY_COUNT(EExpenseType, EExpenseType::Max);

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UEconomyService : public UObject
{
	GENERATED_BODY()

public:
	explicit UEconomyService(const FObjectInitializer& ObjectInitializer);

	// Functions
	UFUNCTION()
	void UpdateTreasury();

	UFUNCTION()
	void UpdateTax(const int32 TotalTaxablePops) const;

	// Getters
	UFUNCTION()
	UEconomyData* GetEconomyData() const;

	UFUNCTION()
	const TMap<EIncomeType, int32>& GetIncomeSources() const;
	
	UFUNCTION()
	const TMap<EExpenseType, int32>& GetExpenseSources() const;

	// Setters

private:
	// Functions
	UFUNCTION()
	void InitialiseMonetarySources();
	
	// Components
	UPROPERTY()
	UEconomyData* EconomyData{ nullptr };
	
	UPROPERTY()
	const UTaxService* TaxService{ nullptr };

	UPROPERTY()
	UFinanceCalculator* FinanceCalculator{ nullptr };

	// Member Variables
	UPROPERTY()
	TMap<EIncomeType, int32> IncomeSources;
	
	UPROPERTY()
	TMap<EExpenseType, int32> ExpenseSources;
};
