// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EconomyManager.generated.h"

struct FEconomyInfo;

UCLASS()
class PROJECTMARS_API UEconomyManager : public UObject
{
	GENERATED_BODY()

public:
	UEconomyManager();
	
	FEconomyInfo* GetEconomyInfo() const;
	UEconomyManager* SetEconomyInfo(FEconomyInfo* EconomyInfoVar);
	void UpdateTreasury() const;
	void AddToListOfIncomeSources(int32 IncomeSourceVar);
	
	const TArray<int32>& GetListOfIncomeSources() const;
	UEconomyManager* SetListOfIncomeSources(const TArray<int32>& ListOfIncomeSourcesVar);


private:
	FEconomyInfo* EconomyInfo{ nullptr };
	TArray<int32> ListOfIncomeSources{};
	
	void CalculateSumOfIncome(const TArray<int32>& ListOfIncomeSourcesVar) const;
	void CalculateNetIncome() const;
};
