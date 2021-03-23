// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayerStateBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API APlayerStateBase : public APlayerState
{
	GENERATED_BODY()

public:
	APlayerStateBase();
	
	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;
};