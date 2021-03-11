// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ReligionBase.generated.h"

UENUM()
enum class EReligion
{
	Hellenism,
	Druidism,
	Zoastrianism
};

UCLASS()
class PROJECTMARS_API UReligionBase : public UObject
{
	GENERATED_BODY()
	
};
