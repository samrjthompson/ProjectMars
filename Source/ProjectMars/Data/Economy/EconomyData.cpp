// Fill out your copyright notice in the Description page of Project Settings.


#include "../../Data/Economy/EconomyData.h"

FEconomyData::FEconomyData()
{
	SumOfOutgoings = 1000.0f;
	GrossIncomePerMonth = 5000.0f;
}

FEconomyData::~FEconomyData()
{
}

void FEconomyData::SetPlayerTreasury(float aMoney)
{
	PlayerTreasury += aMoney;
}

void FEconomyData::UpdatePlayerTreasury()
{
	CalculateNetIncomePerMonth();

	SetPlayerTreasury(NetIncomePerMonth);
	const float NewTreasury = GetPlayerTreasury();

	const FString Treasury = FString::SanitizeFloat(NewTreasury);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Orange, "Current treasury: " + Treasury, true);
}

float FEconomyData::GetPlayerTreasury() const
{
	return PlayerTreasury;
}

float FEconomyData::GetSumOfOutgoings() const
{
	return SumOfOutgoings;
}

float FEconomyData::GetGrossIncomePerMonth() const
{
	return GrossIncomePerMonth;
}

float FEconomyData::GetNetIncomePerMonth() const
{
	return NetIncomePerMonth;
}

void FEconomyData::CalculateNetIncomePerMonth()
{
	NetIncomePerMonth = GrossIncomePerMonth - SumOfOutgoings;
}
