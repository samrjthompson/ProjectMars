// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProductionItem.h"
#include "UObject/Object.h"
#include "FarmingItem.generated.h"

UENUM()
enum class EFarmingItem : uint8
{
	Vegetables,
	Livestock,
	Grapes,
	Olives,
	Wine,
	Grain,
	Wood,
	
	Max UMETA(Hidden)
};
ENUM_RANGE_BY_COUNT(EFarmingItem, EFarmingItem::Max)

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UFarmingItem : public UProductionItem
{
	GENERATED_BODY()

public:

protected:

private:
	
};
