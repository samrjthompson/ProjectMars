// Fill out your copyright notice in the Description page of Project Settings.


#include "NationBuilder.h"

#include "Nation.h"

UNationBuilder::UNationBuilder()
{
	
}

TMap<FString, UNation*>& UNationBuilder::BuildNations(const TArray<FString>& FactionTagsVar)
{
	// TODO: The list of nations will be defined in a JSON file instead of this array
	int32 Index = 0;
	for (const auto Tag : FactionTagsVar)
	{
		UNation* Nation = NewObject<UNation>();
		Nation->SetFactionTag(Tag);
		Nations.Add(FactionTagsVar[Index], Nation);
		Index++;
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
