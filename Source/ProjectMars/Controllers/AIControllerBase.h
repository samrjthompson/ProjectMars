// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API AAIControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	const bool bIsPlayerController{ false };
	
};
