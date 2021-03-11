// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CultureBase.generated.h"

UENUM()
enum class ECulture : uint8
{
	Roman UMETA(DisplayName = "Roman"),
	Etruscan UMETA(DisplayName = "Etruscan"),
	Punic
};

UENUM()
enum class ECultureGroup : uint8
{
	Italic	UMETA(DisplayName = "Italic"),
	Phoenician UMETA(DisplayName = "Phoenician"),
	Greek	UMETA(DisplayName = "Greek"),
	Celtic
};

USTRUCT()
struct FCultureData
{
	GENERATED_BODY()

	FCultureData();
};

UCLASS()
class PROJECTMARS_API UCultureBase : public UObject
{
	GENERATED_BODY()

public:
	UCultureBase();

protected:
	
	
};