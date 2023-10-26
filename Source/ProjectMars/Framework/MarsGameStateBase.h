// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"

#include "MarsGameStateBase.generated.h"

class AProjectMarsPlayer;
class AFactionBase;
class UDelegateController;
class AFactionManager;
class UState;

enum class EMonthOfYear;

struct FCampaignDateTime;

UCLASS()
class PROJECTMARS_API AMarsGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMarsGameStateBase();

	virtual void BeginPlay() override;

	UFUNCTION()
	UState* GetStateForPlayer(FString StateName) const;

	UPROPERTY()
	TMap<FString, UState*> States;

	UFUNCTION()
	class AProjectMarsPlayer* GetPlayer();

	UFUNCTION()
	class ABasePlayerController* GetPlayerController() const;

	UFUNCTION()
	void AddPlayerToPlayerArray(AProjectMarsPlayer* ProjectMarsPlayer);

	UFUNCTION()
	static AActor* PassActorToSelf(AActor* ActorToPass);

	UFUNCTION()
	UDelegateController* GetDelegateController() const;

	UFUNCTION()
	AFactionManager* GetFactionManager() const;

	UFUNCTION()
	class ABaseHUD* GetBaseHUD() const;

	UFUNCTION()
	void SetFactionManager(AFactionManager* FactionMan);

	UFUNCTION()
	void SetDelegateController(UDelegateController* ptr);

	UFUNCTION()
	class UPlayerManagerComponent* GetPlayerManagerComponent() const;
	
	/* Function that initialises pointers by being called from the player class and having the player class 'this'
	 pointer being passed as the argument. */
	void InitialiseReferences(AProjectMarsPlayer* InitPlayer);

	// Returns the time since the passed parameter (in seconds)
	static double GetTimeSince(double StartTime);
	
	// Initialises the passed argument with a start time in seconds
	static void SetStartTime(double& StartTime);

	void LogEveryFiveSeconds();
	
protected:
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY()
	class ABasePlayerController* PlayerController{ nullptr };

	UPROPERTY()
	class AAIControllerBase* AIController{ nullptr };

	UPROPERTY()
	AProjectMarsPlayer* Player{ nullptr };

	UPROPERTY()
	class ABaseHUD* BaseHUD{ nullptr };

	UPROPERTY()
	class UPlayerManagerComponent* PlayerManagerComponent{ nullptr };
	
	TArray<AProjectMarsPlayer*> AllPlayers{ nullptr };
	
	// DelegateManager is initialised by UDelegateController - see UDelegateController::PassSelfToGameState()
	UPROPERTY()
	UDelegateController* DelegateController{ nullptr };

	UPROPERTY()
	AFactionManager* FactionManager{ nullptr };

	double LogTickCheck{};


};