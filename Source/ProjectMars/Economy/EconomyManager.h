// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EconomyManager.generated.h"

struct FEconomyInfo;

class UIncomeCalculator;
class UOutgoingsCalculator;

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
enum class EExpenditureType : uint8
{
	Army,
	Navy,
	Tribute,
	Corruption,

	Max UMETA(Hidden)
};
ENUM_RANGE_BY_COUNT(EExpenditureType, EExpenditureType::Max);

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
	const TMap<EIncomeType, int32>& GetMapOfIncomeSources() const;
	const TMap<EExpenditureType, int32>& GetMapOfOutgoingSources() const;

	// Setters
	UEconomyManager* SetIncomeCalculator(UIncomeCalculator* IncomeCalculatorVar);
	UEconomyManager* SetOutgoingsCalculator(UOutgoingsCalculator* OutgoingsCalculatorVar);
	UEconomyManager* SetMapOfIncomeSources(const TMap<EIncomeType, int32>& MapOfIncomeSourcesVar);
	UEconomyManager* SetMapOfOutgoingSources(const  TMap<EExpenditureType, int32>& MapOfOutgoingSourcesVar);


private:
	UPROPERTY()
	UIncomeCalculator* IncomeCalculator{ nullptr };
	UPROPERTY()
	UOutgoingsCalculator* OutgoingsCalculator{ nullptr };

	// Structs
	FEconomyInfo* EconomyInfo{ nullptr };

	// Maps
	TMap<EIncomeType, int32> MapOfIncomeSources;
	TMap<EExpenditureType, int32> MapOfOutgoingSources;

	void InitialiseMapOfIncomeSources();
};
