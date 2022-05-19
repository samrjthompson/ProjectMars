// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "PlayerManagerComponent.generated.h"

class AProjectMarsPlayer;
class ABasePlayerController;
class AAIControllerBase;
class AMarsGameStateBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTMARS_API UPlayerManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerManagerComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void InitialiseRefs();

	UFUNCTION()
	AMarsGameStateBase* GetGameState() const;
	
	UFUNCTION()
	TArray<AProjectMarsPlayer*>& GetAllPlayersArray();

	UFUNCTION()
	AProjectMarsPlayer* GetPlayer() const;

	UFUNCTION()
	ABasePlayerController* GetPlayerController() const;

	UFUNCTION()
	AAIControllerBase* GetAIController() const;

	UFUNCTION()
	void AssignAIFactions();

	UFUNCTION()
	void CreateArrayOfAvailableFactions();

	UFUNCTION()
	TArray<enum EFactionName>& GetAllFactionsArray();

	UFUNCTION()
	TArray<enum EFactionName>& GetAvailableFactionsArray() const;

	UFUNCTION()
	TArray<AProjectMarsPlayer*>& GetAIPlayersArray();

	UFUNCTION()
	class ADelegateManager* GetDelegateManager() const;

	UFUNCTION()
	void SetDelegateManager(class ADelegateManager* DM);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TArray<AProjectMarsPlayer*> AllPlayers{ nullptr };
	
	UPROPERTY()
	AProjectMarsPlayer* Player{ nullptr };

	UPROPERTY()
	ABasePlayerController* PlayerController{ nullptr };

	UPROPERTY()
	AAIControllerBase* AIController{ nullptr };

	UPROPERTY()
	AMarsGameStateBase* GameState{ nullptr };

	UPROPERTY()
	TArray<EFactionName> AllFactionsArray;
	
	TArray<enum EFactionName>* AvailableFactionsArray;

	UPROPERTY()
	TArray<AProjectMarsPlayer*> AIPlayersArray;

	UPROPERTY()
	class ADelegateManager* DelegateManager{ nullptr };
};
