// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EconomyInfo.generated.h"

USTRUCT()
struct PROJECTMARS_API FEconomyInfo
{
	GENERATED_BODY()

	FEconomyInfo();
	~FEconomyInfo();

	int32 GetTreasury() const;
	FEconomyInfo* SetTreasury(const int32 TreasuryVar);

	int32 GetSumOfOutgoings() const;
	FEconomyInfo* SetSumOfOutgoings(const int32 SumOfOutgoingsVar);

	int32 GetSumOfIncome() const;
	FEconomyInfo* SetSumOfIncome(const int32 SumOfIncomeVar);

	int32 GetNetIncome() const;
	FEconomyInfo* SetNetIncome(const int32 NetIncomeVar);

private:
	int32 Treasury{};
	int32 SumOfOutgoings{};
	int32 SumOfIncome{};
	int32 NetIncome{};
};
