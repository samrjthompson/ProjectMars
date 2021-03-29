// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectMars/Factions/Cultures/CultureBase.h"
#include "ProjectMars/Factions/Economy/Economy.h"
#include "ProjectMars/Factions/Population/PopulationBase.h"

#include "FactionBase.generated.h"

// Seem to have to forward declare the enums
enum class ECultureGroup : uint8;
enum class ECultureName : uint8;
enum class EPoliticalSystem : uint8;

struct FFaction;
struct FPopulation;
struct FCultureGroup;
struct FEconomics;

class AArmy;

// Enum to define the type of political system a faction has
UENUM()
enum class EPoliticalSystem : uint8
{
	Republic = 0,
	TribalRepublic,
	Monarchy,
	Tribe,
	Empire,
	Max
};

USTRUCT()
struct FPolitics
{
	GENERATED_BODY()

	FPolitics();

	// Enum to define the type of political system a faction has
	EPoliticalSystem PoliticalSystem;
};

UENUM()
enum class EFactionName : uint8
{
	Rome = 0,
	Etruria,
	Carthage,
	Max
};

USTRUCT()
struct FFaction
{
	GENERATED_BODY()

	FFaction();
	FFaction(EFactionName InitFaction);

	// Name
	FName FactionName{};
	EFactionName Faction;

	// Population
	int32 TotalPopulation{};

	// Politics
	float PoliticalPowerIncome{};
	float TotalPoliticalPower{};
	float TotalStability{};
	float StabilityChange{};
	float TotalTyranny{ 0 };
	float TyrannyChange{};

	// Military
	float TotalAggressiveExpansion{ 0 };
	float AggressiveExpansionChange{};
	float TotalWarExhaustion{ 0 };
	float WarExhaustionChange{};
	float TotalMilitaryXP{ 0 };
	float MilitaryXPChange{};

	
////////////////////////////////////////////////////////////////////////////////
// FACTION DATA

	/* The faction data is where we store objects that all factions will have. Each player (incl. AI)
	 * will have their own FFaction object and each FFaction object will contain objects that relate
	 * to components of a faction. I.e. Each player has a faction, but a player does not have a population
	 * (for example), or an economy. This belongs to the faction. Each player has a faction, and each
	 * faction has a population/economy etc. */

	// Enums
	EFactionName FactionType;
	
	// Structs
	FPopulation Population;
	FEconomics Economics;
	FCultureGroup CultureGroup;
	FCultureData CultureData;
	FPolitics Politics;
};

UCLASS()
class PROJECTMARS_API AFactionBase : public AActor
{
	GENERATED_BODY()

	friend class AProjectMarsPlayer;
	friend class ABaseHUD;

public:
	AFactionBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	FVector CapitalLocation{};


	//////////////////////////////////////////////////////
	// FACTION DATA
	
public:

	FFaction Faction;
	
	
	//////////////////////////////////////////////////////
	// POPULATION
	
public:
	
	// This is a virtual function that returns a reference to an FPopulation object
	virtual FPopulation& GetRefToPopulationData();
	

	//////////////////////////////////////////////////////
	// ECONOMY

public:
	
	// This is a virtual function that returns a reference to an FEconomics object
	virtual FEconomics& GetRefToEconomicsData();
	
	
	//////////////////////////////////////////////////////
	// CULTURE

public:
	
	// This is a virtual function that returns a reference to an FCultureGroup object
	virtual FCultureGroup& GetRefToCultureGroup();
	virtual FCultureData& GetRefToCultureData();

	
	//////////////////////////////////////////////////////
	// ARMY

public:
	// Pointer to an army a faction has
	UPROPERTY()
	AArmy* FactionArmy{ nullptr };
};