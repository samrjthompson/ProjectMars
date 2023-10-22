// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProductionItem.h"
#include "UObject/Object.h"
#include "ManufactoringItem.generated.h"

UENUM()
enum class EManufacturingItem : uint8
{
	Clothing,
	Pottery,
	Textiles,
	Glassware,
	
	Max UMETA(Hidden)
};
ENUM_RANGE_BY_COUNT(EManufacturingItem, EManufacturingItem::Max)

/**
 * 
 */
UCLASS()
class PROJECTMARS_API UManufacturingItem : public UProductionItem
{
	GENERATED_BODY()
};
