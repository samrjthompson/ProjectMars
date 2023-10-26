// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

class AProjectMarsPlayer;
class ABaseHUD;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRMBPressed);

UCLASS()
class PROJECTMARS_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABasePlayerController();

	// Functions
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupInputComponent() override;

	// Properties
	FOnRMBPressed OnRMBPressed;
	
private:
	// Functions
	UFUNCTION()
	void MovePlayerPawnForwardOrBack(float Val);

	UFUNCTION()
	void MovePlayerPawnRightOrLeft(float Val);
	
	UFUNCTION()
	void OnLMBClick();

	UFUNCTION()
	void OnRMBClick();

	UFUNCTION()
	void InitialisePointers();
	
	// Properties
	UPROPERTY(EditAnywhere)
	AProjectMarsPlayer* PlayerPawn{ nullptr };
	
	UPROPERTY(EditAnywhere)
	ABaseHUD* HUD{ nullptr };

protected:
	virtual void BeginPlay() override;
};
