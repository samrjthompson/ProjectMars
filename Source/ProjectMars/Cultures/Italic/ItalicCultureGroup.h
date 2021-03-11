// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectMars/Cultures/CultureBase.h"
#include "ItalicCultureGroup.generated.h"


UCLASS()
class PROJECTMARS_API UItalicCultureGroup : public UCultureBase
{
	GENERATED_BODY()

public:
	UItalicCultureGroup();

	ECultureGroup CultureGroup;
	
};
