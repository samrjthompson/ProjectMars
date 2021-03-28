// Fill out your copyright notice in the Description page of Project Settings.


#include "Army.h"

#include "Components/BoxComponent.h"
#include "ProjectMars/Military/UnitBase.h"

// Sets default values
AArmy::AArmy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Army Mesh"));
	Mesh->SetupAttachment(Root);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBox->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void AArmy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArmy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

