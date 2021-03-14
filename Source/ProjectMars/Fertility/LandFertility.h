// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LandFertility.generated.h"

UENUM()
enum class EFertilityLevel
{
	VeryLow,
	Low,
	Medium,
	High,
	VeryHigh,
	Superior
};

UCLASS()
class PROJECTMARS_API ALandFertility : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALandFertility();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
