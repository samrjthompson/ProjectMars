// Fill out your copyright notice in the Description page of Project Settings.


#include "Army.h"

#include "Components/BoxComponent.h"

FLegion::FLegion()
{
}

FCohort::FCohort()
{
}

FInfantry::FInfantry()
{
}

// Sets default values
AArmy::AArmy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Army Mesh"));
	Mesh->SetupAttachment(Root);
	//Mesh->OnClicked.AddDynamic(this, &AArmy::ArmyHasBeenClickedOn);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	TriggerBox->SetupAttachment(Mesh);
}

// Called when the game starts or when spawned
void AArmy::BeginPlay()
{
	Super::BeginPlay();
	
}

AArmy* AArmy::ArmyHasBeenClickedOn()
{
	return this;
}

// Called every frame
void AArmy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}