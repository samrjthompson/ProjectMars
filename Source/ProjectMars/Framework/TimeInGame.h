// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimeInGame.generated.h"

USTRUCT()
struct FCampaignDateTime
{
	GENERATED_BODY()
	
	FCampaignDateTime();

	int32 DayOfMonth{};

	void UpdateDayOfMonth(const EMonthOfYear& MonthOfYear);

		
};

UCLASS()
class PROJECTMARS_API UTimeInGame : public UObject
{
	GENERATED_BODY()
	
	UTimeInGame();
	
};
