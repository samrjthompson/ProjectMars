// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FactionManager.generated.h"

UCLASS()
class PROJECTMARS_API AFactionManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFactionManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void PassSelfToGameStateBase();

	UFUNCTION()
	TArray<FString>& GetAllFactionNames();

	UFUNCTION()
	void SetFactionNames();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class AMarsGameStateBase* GameStateBase{ nullptr };
	
	TArray<FString> AllFactionNames;
	
	//TArray<FString>* AllFactionNamesPtr{ nullptr };
};
