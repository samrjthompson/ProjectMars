// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectMars/Factions/FactionBase.h"
#include "EtruriaFaction.generated.h"

struct FBaseFactionData;

UCLASS()
class PROJECTMARS_API UEtruriaFaction : public UFactionBase
{
	GENERATED_BODY()

public:
	UEtruriaFaction();
	
	FBaseFactionData EtruriaFactionData;	
};
