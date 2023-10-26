// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "ProjectMarsPlayer.generated.h"

class USceneComponent;
class USpringArmComponent;
class UCameraComponent;
class APlayerState;
class AMarsGameStateBase;
class ABaseHUD;
class ABasePlayerController;
class AArmy;

/**
 * This class is the physical representation of the player in the game world. It allows for interaction with in game
 * objects and UI.
 */
UCLASS()
class PROJECTMARS_API AProjectMarsPlayer : public APawn
{
	friend class ABaseHUD;
	friend class AMarsGameStateBase;
	
	GENERATED_BODY()

public:
	AProjectMarsPlayer();

	// Functions
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void MoveForwardOrBack(float Val);
	
	UFUNCTION()
	void MoveRightOrLeft(float Val);

	UFUNCTION()
	void FilterActorClickedOn(AActor* ActorVar);

	UFUNCTION()
	void IssueMoveArmyOrder();

private:
	// Properties
	UPROPERTY(EditAnywhere)
	USceneComponent* RootComp{ nullptr };

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArmComp{ nullptr };

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera{ nullptr };

	UPROPERTY(EditAnywhere)
	ABasePlayerController* BasePlayerController{ nullptr };

	UPROPERTY(EditAnywhere)
	APlayerState* MyPlayerState{ nullptr };

	UPROPERTY(EditAnywhere)
	AMarsGameStateBase* MarsGameStateBase{ nullptr };

	UPROPERTY(EditAnywhere)
	ABaseHUD* BaseHUD{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector MovementDirection{};

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, Category = "Actors Clicked On")
	const AActor* ActorClickedOn{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Actors Clicked On")
	AArmy* ArmyClickedOn{ nullptr };

	// Functions
	UFUNCTION()
	void InitialisePointers();

	UFUNCTION()
	void SubscribeToDelegateEvents();
	
	UFUNCTION()
	void MovePlayerPawn(float DeltaTime);

protected:
	virtual void BeginPlay() override;



	int32 ClickCounter = 0;
};