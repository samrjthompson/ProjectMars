// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Resources.generated.h"

UENUM()
enum class EResourceType
{
	// Try to keep in alphabetical order
	Cloth,
	Dye,
	Glass,
	Gold,
	Grain,
	Iron,
	Jewels,
	Livestock,
	Marble,
	Olives,
	Silver,
	Slaves,
	Stone,
	Tin,
	Wine,
	None
};

USTRUCT()
struct FResource
{
	GENERATED_BODY()
	
};