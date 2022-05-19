// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EconomyData.generated.h"

/**
 * 
 */
USTRUCT()
struct PROJECTMARS_API FEconomyData
{
	GENERATED_BODY()

public:
	FEconomyData();
	~FEconomyData();

public:
	void SetPlayerTreasury(float aMoney);
	
	void UpdatePlayerTreasury();

	float GetPlayerTreasury() const;

	float GetSumOfOutgoings() const;

	float GetGrossIncomePerMonth() const;

	float GetNetIncomePerMonth() const;

	void CalculateNetIncomePerMonth();

private:
	float PlayerTreasury{};

	float SumOfOutgoings{};

	float GrossIncomePerMonth{};

	float NetIncomePerMonth{};
};
