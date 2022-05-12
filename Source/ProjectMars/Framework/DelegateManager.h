// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MarsGameStateBase.h"
#include "GameFramework/Actor.h"
#include "DelegateManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTestDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMonthlyUpdate);

UCLASS()
class PROJECTMARS_API ADelegateManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelegateManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

private:
	AMarsGameStateBase* MarsGameStateBase{ nullptr };

	void PassSelfToGameState();

	// Delegates
public:
	FOnTestDelegate OnTestDelegate;
	FOnMonthlyUpdate OnMonthlyUpdate;
};
