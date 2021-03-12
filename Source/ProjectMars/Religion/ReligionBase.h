// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ReligionBase.generated.h"

UENUM()
enum class EReligion
{
	Hellenism,
	Druidism,
	Zoroastrianism
};

UCLASS()
class PROJECTMARS_API AReligionBase : public AActor
{
	GENERATED_BODY()
	
};
