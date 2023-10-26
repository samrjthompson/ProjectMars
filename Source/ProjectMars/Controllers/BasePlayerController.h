// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

class AProjectMarsPlayer;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRMBPressed);

UCLASS()
class PROJECTMARS_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
private:
	void MovePlayerPawnForwardOrBack(float Val);
	void MovePlayerPawnRightOrLeft(float Val);

	void OnLMBClick();

	UPROPERTY()
	AProjectMarsPlayer* PlayerPawn{ nullptr };

public:
	ABasePlayerController();

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupInputComponent() override;

	bool bGameIsPaused = true;

	void PauseGame();

protected:
	virtual void BeginPlay() override;

private:
	void SelectionPressed();
	void SelectionReleased();

public:
	FOnRMBPressed OnRMBPressed;

	UFUNCTION()
	void RMBPressed();

	UPROPERTY()
	class ABaseHUD* HUD{ nullptr };
};
