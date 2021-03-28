// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Army.generated.h"

UCLASS()
class PROJECTMARS_API AArmy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArmy();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

	/////////////////////////////////////////////////////////////
	// BASE COMPONENTS

public:

	UPROPERTY(EditAnywhere)
	class USceneComponent* Root{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Mesh")
	class UStaticMeshComponent* Mesh{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	class UBoxComponent* TriggerBox{ nullptr };
	

	/////////////////////////////////////////////////////////////
	// ARMY COMPOSITION

public:

	TArray<struct FUnitData*> ArmyUnitsArray;
};