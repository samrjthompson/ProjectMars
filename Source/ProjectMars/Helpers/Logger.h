// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Logger.generated.h"

enum EVerbosityLevels
{
	Warning,
	Error
};

/**
 * 
 */
USTRUCT()
struct PROJECTMARS_API FLogger
{
	GENERATED_BODY()

	static void Log(FString StringVal);
	static void Log(int32 IntVal);
	static void Log(float FloatVal);
	static void Log(double DoubleVal);
};
