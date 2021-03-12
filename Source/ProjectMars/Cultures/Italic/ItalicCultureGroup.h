// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectMars/Cultures/CultureBase.h"
#include "ItalicCultureGroup.generated.h"

USTRUCT()
struct FItalicCultureGroupType : public FCultureGroup
{
	GENERATED_BODY()

	FItalicCultureGroupType();

		
};

UCLASS()
class PROJECTMARS_API AItalicCultureGroup : public ACultureBase
{
	GENERATED_BODY()

public:
	AItalicCultureGroup();

	ECultureGroup CultureGroup;
	
};
