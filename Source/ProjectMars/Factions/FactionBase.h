// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectMars/Cultures/CultureBase.h"
#include "ProjectMars/Economy/Economy.h"
#include "ProjectMars/Population/PopulationBase.h"

#include "FactionBase.generated.h"

// Seem to have to forward declare the enums
enum class ECultureGroup : uint8;
enum class ECultureName : uint8;

struct FFaction;
struct FPopulation;
struct FCultureGroup;
struct FFactionEconomics;


UENUM()
enum class EFactionName : uint8
{
	Rome = 0,
	Etruria,
	Carthage,
	MAX
};

USTRUCT()
struct FFaction
{
	GENERATED_BODY()

	FFaction()
	{
		
	}
	FFaction(EFactionName InitFaction)
	{
		Faction = InitFaction;
	}

	// Name
	FName FactionName{};
	EFactionName Faction;

	// Population
	int32 TotalPopulation{};
	int32 Manpower{};

	// Politics
	float PoliticalPowerIncome{};
	float TotalPoliticalPower{};
	float TotalStability{};
	float StabilityChange{};
	float TotalTyranny{};
	float TyrannyChange{};

	// Military
	float TotalAggressiveExpansion{};
	float AggressiveExpansionChange{};
	float TotalWarExhaustion{};
	float WarExhaustionChange{};
	float TotalMilitaryXP{};
	float MilitaryXPChange{};

	FPopulation FactionPop;
	FFactionEconomics Economics;
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


	/****************************************************************/
	/* FACTION DATA */

	FPopulation Population;

public:
	inline virtual FName GetFactionName() const { return FactionName; }
	inline void SetFactionName(FString Name) { FactionName = FName(Name); }
	
	// This is a virtual function that returns a reference to an FFaction object 
	virtual FFaction& GetRefToFactionData();


	
private:
	
	
protected:
	FName FactionName{};
	
	EFactionName FactionType;

	// Objects by value of faction data structs
	FFaction BaseFactionData;
	
	
	/****************************************************************/
	/* POPULATION */
	
public:
	// This is a virtual function that returns a reference to an FPopulation object
	virtual FPopulation& GetRefToPopulationData();
	
private:
	
protected:

	

	/****************************************************************/
	/* ECONOMY */

public:
	// This is a virtual function that returns a reference to an FFactionEconomics object
	virtual FFactionEconomics& GetRefToEconomicsData();
	
private:
	
protected:
	FFactionEconomics FactionEconomics;
	
	
	/****************************************************************/
	/* CULTURE */

public:
	// This is a virtual function that returns a reference to an FCultureGroup object
	virtual FCultureGroup& GetRefToCultureGroup();
	virtual FCultureData& GetRefToCultureData();

private:

protected:
	ECultureGroup CultureGroup;
	ECultureName Culture;
	FCultureGroup CultureGroupObj;
	FCultureData CultureDataObj;
};