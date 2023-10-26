// Fill out your copyright notice in the Description page of Project Settings.


#include "NationBuilder.h"

#include "Nation.h"

UNationBuilder::UNationBuilder()
{
	
}

TMap<FString, UNation*>& UNationBuilder::BuildNations()
{
	// TODO: The list of nations will be defined in a JSON file instead of this array
	TArray<FString> NationNames { "Rome", "Etruria", "Samnium" };

	constexpr int32 NumOfNations = 3;
	for (int32 i = 0; i < NumOfNations; i++)
	{
		UNation* Nation = NewObject<UNation>();
		Nations.Add(NationNames[i], Nation);
	}
	return Nations;
}

const TMap<FString, UNation*>& UNationBuilder::AddNation(const FString& NationNameVar, UNation* NationVar)
{
	Nations.Add(NationNameVar, NationVar);
	return Nations;
}

const TMap<FString, UNation*>& UNationBuilder::GetNations() const
{
	return Nations;
}
