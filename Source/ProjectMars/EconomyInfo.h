// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EconomyInfo.generated.h"

USTRUCT()
struct PROJECTMARS_API FEconomyInfo
{
	GENERATED_BODY()
public:
	FEconomyInfo();
	~FEconomyInfo();

	float GetTreasury() const;
	FEconomyInfo* SetTreasury(float TreasuryVar);

private:
	float Treasury{};

};
