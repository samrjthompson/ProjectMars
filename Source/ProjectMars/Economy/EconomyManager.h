// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EconomyManager.generated.h"

struct FEconomyData;

class UFinanceCalculator;
class UDelegateController;

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

UCLASS()
class PROJECTMARS_API UEconomyManager : public UObject
{
	GENERATED_BODY()

public:
	UEconomyManager();

	// Getter
	FEconomyData* GetEconomyData() const;
	const TMap<EIncomeType, int32>* GetIncomeSources() const;
	const TMap<EExpenseType, int32>* GetExpenseSources() const;

	// Setter
	UEconomyManager* SetEconomyData(FEconomyData* EconomyDataVar);
	
	UFUNCTION()
	void UpdateTreasury();

private:
	UPROPERTY()
	UFinanceCalculator* FinanceCalculator{ nullptr };

	UPROPERTY()
	UDelegateController* DelegateController { nullptr };

	// Structs
	FEconomyData* EconomyData{ nullptr };

	// Maps
	UPROPERTY()
	TMap<EIncomeType, int32> IncomeSources;
	UPROPERTY()
	TMap<EExpenseType, int32> ExpenseSources;

	// Functions
	UFUNCTION()
	void InitialiseMonetarySources();

	UFUNCTION()
	void InitialiseDelegateEvents();
};
