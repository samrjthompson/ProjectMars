// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EconomyManager.generated.h"

struct FEconomyInfo;

class UIncomeCalculator;

UENUM()
enum class EIncomeSourceType : uint8
{
	TaxIncome = 0,
	TradeIncome,

	Max
};

UCLASS()
class PROJECTMARS_API UEconomyManager : public UObject
{
	GENERATED_BODY()

public:
	UEconomyManager();
	
	FEconomyInfo* GetEconomyInfo() const;
	UEconomyManager* SetEconomyInfo(FEconomyInfo* EconomyInfoVar);
	void UpdateTreasury() const;

	// Getters
	const UIncomeCalculator* GetIncomeCalculator() const;
	const TMap<EIncomeSourceType, int32>& GetMapOfIncomeSources() const;

	// Setters
	UEconomyManager* SetIncomeCalculator(UIncomeCalculator* IncomeCalculatorVar);
	UEconomyManager* SetMapOfIncomeSources(const TMap<EIncomeSourceType, int32>& MapOfIncomeSourcesVar);


private:
	UPROPERTY()
	UIncomeCalculator* IncomeCalculator{ nullptr };
	
	FEconomyInfo* EconomyInfo{ nullptr };

	// TODO: In the future this will store objects of sources, not integers
	TMap<EIncomeSourceType, int32> MapOfIncomeSources;
};
