// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MarsGameStateBase.generated.h"


UCLASS()
class PROJECTMARS_API AMarsGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMarsGameStateBase();

	virtual void BeginPlay() override;

protected:
	virtual void Tick(float DeltaSeconds) override;
};
