// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Army.generated.h"

struct FCohort;

class AProjectMarsPlayer;

UENUM()
enum class EArmyMovementStance : uint8
{
	Stationary = 0,
	March,
	Siege,
	Raid,
	Ambush,
	Patrol,
	Max	
};

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
struct FCohort
{
	GENERATED_BODY()

	FCohort();

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
	int32 MaxNumOfTroops{ 500 };
	int32 StartingNumOfTroops{ MaxNumOfTroops };
	int32 MinNumOfTroops{ 0 };

	// TEXTURE
	UPROPERTY()
	class UTexture2D* UnitIcon{ nullptr };

	FName UnitName = "NONE";
};

USTRUCT()
struct FLegion
{
	GENERATED_BODY()

	FLegion();

	// Each array is 1 legion which == 5,000 men which == 10 units/cohorts
	TArray<FCohort> Legion[10];
};

UENUM()
enum class ESpecialInfantryTrait : uint8
{
	None = 0,
	Max
};

USTRUCT()
struct FInfantry : public FCohort
{
	GENERATED_BODY()

	FInfantry();

	ESpecialInfantryTrait SpecialInfantryTrait;

};

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
	

	//////////////////////////////////////////////////////
	// BASE COMPONENTS
public:

	UPROPERTY(EditAnywhere)
	class USceneComponent* Root{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Mesh")
	class UStaticMeshComponent* Mesh{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Trigger Box")
	class UBoxComponent* TriggerBox{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Icon")
	class UTexture2D* ArmyIcon{ nullptr };

public:
	//////////////////////////////////////////////////////
	// ARMY UNITS
	struct FCohort Cohort;
	struct FLegion Legion;

public:
	//////////////////////////////////////////////////////
	// ARMY STANCE
	enum class EArmyMovementStance ArmyMovementStance;
	
public:
	//////////////////////////////////////////////////////
	// ARMY COMPOSITION
public:

	// Each army is an array (2D array) made up of legions (Legion arrays) (no hard limit on this)
	TArray<TArray<FLegion>*> Army;

	AArmy* ArmyHasBeenClickedOn();


	//////////////////////////////////////////////////////
	// ARMY MOVEMENT
public:

	UPROPERTY(EditAnywhere, Category = "Movement")
	float DefaultMovementSpeed{ 20.f };
	
	float CurrentMovementSpeed{ DefaultMovementSpeed };

	FVector StartLocation{};

	UPROPERTY(EditAnywhere, Category = "Movement", Meta = (MakeEditWidget = true))
	FVector TargetLocation{};

	FVector GlobalTargetLocation{};
	FVector GlobalStartLocation{};

	void MoveArmy();

	bool bArmyIsMoving = false;
	bool bGameIsPaused = true;
	bool bCanMoveArmy = false;

	FVector Direction{};
	FVector ActorLocAtPause{};

	void GetPlayerOwnerOfArmy(AProjectMarsPlayer* PlayerOwner);

	UPROPERTY()
	AProjectMarsPlayer* OwnerOfArmy{ nullptr };

};