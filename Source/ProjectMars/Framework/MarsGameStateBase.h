// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"

#include "MarsGameStateBase.generated.h"

class AProjectMarsPlayer;
class UDelegateController;
class UState;

UCLASS()
class PROJECTMARS_API AMarsGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMarsGameStateBase();

	// Functions
	virtual void BeginPlay() override;

	UFUNCTION()
	void AddPlayerToPlayerArray(AProjectMarsPlayer* ProjectMarsPlayer);

	// Getters
	UFUNCTION()
	UDelegateController* GetDelegateController() const;

	// Setters
	UFUNCTION()
	void SetDelegateController(UDelegateController* ptr);

private:
	UPROPERTY(EditAnywhere)
	TMap<FString, UState*> States;
	
	UPROPERTY(EditAnywhere)
	TArray<AProjectMarsPlayer*> AllPlayers;
	
	UPROPERTY(EditAnywhere)
	UDelegateController* DelegateController{ nullptr };

protected:
	virtual void Tick(float DeltaSeconds) override;
};