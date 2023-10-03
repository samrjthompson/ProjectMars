// Fill out your copyright notice in the Description page of Project Settings.


#include "EconomyInfo.h"


FEconomyInfo::FEconomyInfo()
{
}

FEconomyInfo::~FEconomyInfo()
{
}

float FEconomyInfo::GetTreasury() const
{
	return Treasury;
}

FEconomyInfo* FEconomyInfo::SetTreasury(float TreasuryVar)
{
	Treasury = TreasuryVar;
	return this;
}
