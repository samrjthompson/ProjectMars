// Fill out your copyright notice in the Description page of Project Settings.


#include "../Helpers/Logger.h"


void FLogger::Log(FString StringVal)
{
	UE_LOG(LogTemp, Warning, TEXT("LOG: %s"), *StringVal);
} 

void FLogger::Log(int32 IntVal)
{
	UE_LOG(LogTemp, Warning, TEXT("LOG: %d"), IntVal);
}

void FLogger::Log(float FloatVal)
{
	UE_LOG(LogTemp, Warning, TEXT("LOG: %f"), FloatVal);
}

void FLogger::Log(double DoubleVal)
{
}
