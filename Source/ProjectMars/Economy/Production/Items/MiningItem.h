// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProductionItem.h"
#include "UObject/Object.h"
#include "MiningItem.generated.h"

UENUM()
enum class EMiningItem : uint8
{
	Copper,
	Iron,
	Tin,
	Lead,
	Gold,
	Silver,
	Stone,
	Marble,
	Limestone,
	Gypsum,
	
	Max UMETA(Hidden)
};
ENUM_RANGE_BY_COUNT(EMiningItem, EMiningItem::Max)

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UMiningItem : public UProductionItem
{
	GENERATED_BODY()

	UMiningItem();
};
