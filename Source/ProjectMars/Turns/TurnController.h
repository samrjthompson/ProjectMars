// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TurnController.generated.h"

class UDelegateController;
class AMarsGameStateBase;

/**
 * Contains logic and data relating to the start and end turn processes
 */
UCLASS()
class PROJECTMARS_API UTurnController : public UObject
{
	GENERATED_BODY()

public:
	UTurnController();

	UFUNCTION()
	void BroadcastFirstTurn();
	
	UFUNCTION()
	void EndTurn();

	UFUNCTION()
	void StartNewTurn(const int32 TurnNumberVar);

	UFUNCTION()
	int32 UpdateTurnNumber();

	// Getters
	UFUNCTION()
	int32 GetTurnNumber() const;

	// Setters
	UFUNCTION()
	UTurnController* SetDelegateController(UDelegateController* DelegateControllerVar);

	UFUNCTION()
	UTurnController* SetMarsGameStateBase(AMarsGameStateBase* MarsGameStateBaseVar);

	UFUNCTION()
	UTurnController* SetFactionTags(const TArray<FString>& FactionTagsVar);

	UFUNCTION()
	void SubscribeToDelegates(UDelegateController* DelegateControllerVar);
	
private:
	// Functions
	UFUNCTION()
	const FString& ChangeCurrentTurnOwner();

	UFUNCTION()
	void BroadcastCurrentTurnOwner(const FString& CurrentTurnOwnerVar);
	
	// Properties
	UPROPERTY(EditAnywhere)
	UDelegateController* DelegateController{ nullptr };

	UPROPERTY(EditAnywhere)
	int32 TurnNumber{};

	UPROPERTY(EditAnywhere)
	AMarsGameStateBase* MarsGameStateBase{ nullptr };

	UPROPERTY(EditAnywhere)
	TArray<FString> FactionTags;

	UPROPERTY(EditAnywhere)
	int32 CurrentTurnOwnerIndex;
};
