// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LandFertility.generated.h"

UENUM()
enum class EFertilityLevel
{
	VeryLow,
	Low,
	Medium,
	High,
	VeryHigh,
	Superior
};

USTRUCT()
struct FFertility
{
	GENERATED_BODY()
	
};