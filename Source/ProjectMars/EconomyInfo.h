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
	FEconomyInfo* SetGrossOutgoings(const int32 GrossOutgoingsVar);

	int32 GetSumOfIncome() const;
	FEconomyInfo* SetGrossIncome(const int32 GrossIncomeVar);

	int32 GetNetIncome() const;
	FEconomyInfo* SetNetIncome(const int32 NetIncomeVar);

private:
	int32 Treasury{};
	int32 GrossOutgoings{};
	int32 GrossIncome{};
	int32 NetIncome{};
};
