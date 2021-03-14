// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Resources.generated.h"

UENUM()
enum class EResourceType
{
	// Try to keep in alphabetical order
	Cloth,
	Dye,
	Glass,
	Gold,
	Grain,
	Iron,
	Jewel,
	Livestock,
	Marble,
	Olive,
	Silver,
	Slave,
	Stone,
	Tin,
	Wine,
	None
};


UCLASS()
class PROJECTMARS_API AResources : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AResources();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};