// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"

#include "MarsGameStateBase.generated.h"

class AProjectMarsPlayer;
class UDelegateController;
class UNation;
class UTurnController;

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

	UFUNCTION()
	void LoadFirstTurn();

	// Getters
	UFUNCTION()
	UDelegateController* GetDelegateController() const;

	// Setters
	UFUNCTION()
	void SetDelegateController(UDelegateController* ptr);

private:
	// Functions
	UFUNCTION()
	void InitialiseFactionTags();

	UFUNCTION()
	void BuildNations();
	
	// Properties
	UPROPERTY(EditAnywhere)
	TMap<FString, UNation*> Nations;
	
	UPROPERTY(EditAnywhere)
	TArray<AProjectMarsPlayer*> AllPlayers;
	
	UPROPERTY(EditAnywhere)
	UDelegateController* DelegateController{ nullptr };

	UPROPERTY(EditAnywhere)
	UTurnController* TurnController{ nullptr };

	UPROPERTY(EditAnywhere)
	TArray<FString> FactionTags;

protected:
	virtual void Tick(float DeltaSeconds) override;
};