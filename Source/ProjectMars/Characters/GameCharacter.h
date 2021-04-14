// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameCharacter.generated.h"

// TRAITS
UENUM()
enum class ECharacterTraits
{
	// MARTIAL
	GoodCommander = 0,
	BadCommander,

	Max
};

USTRUCT()
struct FCharacterTraits
{
	GENERATED_BODY()
	
	FCharacterTraits()
	{
		
	}
};

UENUM()
enum class ECharacterState
{
	Alive = 0,
	Dead,

	Max
};

UENUM()
enum class ERank
{
	Low = 0,
	Mid,
	High,
	
	Max
};

USTRUCT()
struct FInGameCharacter
{
	GENERATED_BODY()

	FInGameCharacter()
	{
		
	}

	// APPEARANCE
	class UTexture2D* Portrait{ nullptr };
	FName Name;
	int32 Age;

	// RANK
	enum class ERank CharacterRank;

	// SKILLS
	int32 MartialSkill;
	int32 IntrigueSkill;
	int32 DiplomacySkill;
	int32 FightingSkill;

	ECharacterState CharacterState;

	// TRAIT ENUMS
	ECharacterTraits CharacterTraits;

	TArray<ECharacterTraits> CharacterTraitsArray;


	// TArray<struct FCharacterTraits> CharacterTraitsArray;

	void ApplyTraitModifier(const ECharacterTraits& Trait);
};

UCLASS()
class PROJECTMARS_API AGameCharacter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};