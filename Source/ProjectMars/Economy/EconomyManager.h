// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EconomyManager.generated.h"

struct FEconomyInfo;

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

UCLASS()
class PROJECTMARS_API UEconomyManager : public UObject
{
	GENERATED_BODY()

public:
	UEconomyManager();

	// Getter
	FEconomyInfo* GetEconomyInfo() const;
	const TMap<EIncomeType, int32>* GetIncomeSources() const;

	// Setter
	UEconomyManager* SetEconomyInfo(FEconomyInfo* EconomyInfoVar);
	
	UFUNCTION()
	void UpdateTreasury() const;

private:
	UPROPERTY()
	UFinanceCalculator* FinanceCalculator{ nullptr };

	// Structs
	FEconomyInfo* EconomyInfo{ nullptr };

	// Maps
	UPROPERTY()
	TMap<EIncomeType, int32> IncomeSources;
	UPROPERTY()
	TMap<EExpenseType, int32> ExpenseSources;

	UFUNCTION()
	void InitialiseIncomeSources();
};
