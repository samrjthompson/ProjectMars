// Fill out your copyright notice in the Description page of Project Settings.


#include "PopulationData.h"

UPopulationData::UPopulationData(const FObjectInitializer& ObjInitializer)
	: Super(ObjInitializer),
	StartingTotalPopNum(2000000),
	CurrentTotalPopNum(StartingTotalPopNum),
	CitizenPercentage(0.1f),
	StartingCitizenPopNum(StartingTotalPopNum * CitizenPercentage),
	CurrentCitizenPopNum(StartingCitizenPopNum),
	FightingAgeMalePercentage(0.33f),
	StartingNonCitizenPopNum(StartingTotalPopNum * 0.4f),
	CurrentNonCitizenPopNum(StartingNonCitizenPopNum),
	StartingAlliedClientPopNum(StartingTotalPopNum * 0.2f),
	CurrentAlliedClientPopNum(StartingAlliedClientPopNum),
	StartingSlavePopNum(StartingTotalPopNum * 0.2f),
	CurrentSlavePopNum(StartingSlavePopNum),
	StartingForeignerPopNum(StartingTotalPopNum * 0.1f),
	CurrentForeignerPopNum(StartingForeignerPopNum)
{
}

int32 UPopulationData::CalculateFightingAgeMales() const
{
	return CurrentCitizenPopNum / 2 * FightingAgeMalePercentage;
}

int32 UPopulationData::GetCurrentTotalPopNum() const
{
	return CurrentTotalPopNum;
}

int32 UPopulationData::GetCurrentCitizenPopNum() const
{
	return CurrentCitizenPopNum;
}

int32 UPopulationData::GetCurrentNonCitizenPopNum() const
{
	return CurrentNonCitizenPopNum;
}

int32 UPopulationData::GetCurrentAlliedClientPopNum() const
{
	return CurrentAlliedClientPopNum;
}

int32 UPopulationData::GetCurrentSlavePopNum() const
{
	return CurrentSlavePopNum;
}

int32 UPopulationData::GetCurrentForeignerPopNum() const
{
	return CurrentForeignerPopNum;
}
