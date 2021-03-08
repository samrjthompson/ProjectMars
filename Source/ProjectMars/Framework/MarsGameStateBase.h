// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MarsGameStateBase.generated.h"

class APlayerCameraPawn;

UCLASS()
class PROJECTMARS_API AMarsGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMarsGameStateBase();

	virtual void BeginPlay() override;

	// Function that initialises the pointers via the player class
	void InitialiseReferences(APlayerCameraPawn* InitPlayer);

protected:
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY()
	class ABasePlayerController* PlayerController{ nullptr };

	UPROPERTY()
	APlayerCameraPawn* Player{ nullptr };

	UPROPERTY()
	class ABaseHUD* BaseHUD{ nullptr };


};
