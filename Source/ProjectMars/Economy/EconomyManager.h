// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EconomyManager.generated.h"

struct FEconomyInfo;

class UIncomeCalculator;
class UOutgoingsCalculator;

UENUM()
enum class EIncomeSourceType : uint8
{
	TaxIncome = 0,
	TradeIncome,

	Max
};

UENUM()
enum class EOutgoingsSourceType : uint8
{
	ArmyExpenditure = 0,
	TributeExpenditure,

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
	
	UFUNCTION()
	void UpdateTreasury() const;

	// Getters
	const UIncomeCalculator* GetIncomeCalculator() const;
	const UOutgoingsCalculator* GetOutgoingsCalculator() const;
	const TMap<EIncomeSourceType, int32>& GetMapOfIncomeSources() const;
	const TMap<EOutgoingsSourceType, int32>& GetMapOfOutgoingSources() const;

	// Setters
	UEconomyManager* SetIncomeCalculator(UIncomeCalculator* IncomeCalculatorVar);
	UEconomyManager* SetOutgoingsCalculator(UOutgoingsCalculator* OutgoingsCalculatorVar);
	UEconomyManager* SetMapOfIncomeSources(const TMap<EIncomeSourceType, int32>& MapOfIncomeSourcesVar);
	UEconomyManager* SetMapOfOutgoingSources(const  TMap<EOutgoingsSourceType, int32>& MapOfOutgoingSourcesVar);


private:
	UPROPERTY()
	UIncomeCalculator* IncomeCalculator{ nullptr };
	UPROPERTY()
	UOutgoingsCalculator* OutgoingsCalculator{ nullptr };
	
	FEconomyInfo* EconomyInfo{ nullptr };

	// TODO: In the future this will store objects of sources, not integers
	TMap<EIncomeSourceType, int32> MapOfIncomeSources;
	TMap<EOutgoingsSourceType, int32> MapOfOutgoingSources;
};
