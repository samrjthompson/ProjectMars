// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Resource.generated.h"

UENUM()
enum class EResourceType
{
	Iron,
	Grain,
	Dye,
	Gold,

	None
};

enum class EResourceType;

UCLASS()
class PROJECTMARS_API AResource : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResource();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	EResourceType GetResourceType();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	EResourceType ResourceType;
};
