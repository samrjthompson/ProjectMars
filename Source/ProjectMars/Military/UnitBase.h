// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnitBase.generated.h"

struct FUnitData;

UENUM()
enum class EUnitName : uint8
{
	// ROME
	Hastati = 0, Principes, Triarii, Velites, Equites,

	Max
};

UENUM()
enum class EUnitExperience : uint8
{
	Green = 0,
	Trained,
	Regular,
	Seasoned,
	Veteran,
	Max	
};

UENUM()
enum class EUnitCategory : uint8
{
	Swordsmen = 0,
	Spearmen,
	MissileTroops,
	Cavalry,
	SiegeTroops,
	BaggageTrain,
	Max
};

UENUM()
enum class EUnitClass : uint8
{
	Light = 0,
	Heavy,
	Shock,
	Missile,
	Support,
	Max
};

UENUM()
enum class ETerrainProficiency : uint8
{
	None = 0,
	Forrest,
	Snow,
	Mountain,
	Hill,
	Grassland,
	Amphibious,
	Desert,
	Max
};

UENUM()
enum class EClimateProficiency : uint8
{
	None = 0,
	VeryCold,
	Cold,
	Temperate,
	Hot,
	VeryHot,
	Max
};

USTRUCT()
struct FUnitData
{
	GENERATED_BODY()

	FUnitData();

	EUnitExperience UnitExperience;
	EUnitCategory UnitType;
	EUnitClass UnitClass;
	ETerrainProficiency TerrainProficiency;
	EClimateProficiency ClimateProficiency;

	int32 Armour{};
	int32 WeaponDamage{};
	int32 Speed{};
	int32 Morale{};
	int32 Discipline{};
	int32 Experience{};

	FName UnitName = "NONE";	
};

UENUM()
enum class ESpecialInfantryTrait : uint8
{
	None = 0,
	Max
}; 

USTRUCT()
struct FInfantry : public FUnitData
{
	GENERATED_BODY()

	FInfantry();

	ESpecialInfantryTrait SpecialInfantryTrait;

};

UCLASS()
class PROJECTMARS_API AUnitBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUnitBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//////////////////////////////////////////////////////
	// UNIT STATS
	struct FUnitData UnitStats;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:


};