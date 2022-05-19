// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCharacter.h"

void FInGameCharacter::ApplyTraitModifier(const ECharacterTraits& Trait)
{
	switch(Trait)
	{
		case ECharacterTraits::GoodCommander : this->MartialSkill += 4;
		break;

		case ECharacterTraits::BadCommander : this->MartialSkill += -4;
		break;

		default : this->MartialSkill += 0;
		break;
	}
}

// Sets default values
AGameCharacter::AGameCharacter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

