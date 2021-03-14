// Fill out your copyright notice in the Description page of Project Settings.


#include "LandFertility.h"

// Sets default values
ALandFertility::ALandFertility()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ALandFertility::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALandFertility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}