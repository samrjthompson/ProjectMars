// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectMars/Cultures/CultureBase.h"
#include "ProjectMars/Economy/Economy.h"
#include "ProjectMars/Population/PopulationBase.h"

#include "FactionBase.generated.h"

// Seem to have to forward declare the enums
enum class EFaction : uint8;
enum class ECultureGroup : uint8;
enum class ECultureName : uint8;

struct FBaseFactionData;
struct FPopulation;
struct FCultureGroup;
struct FFactionEconomics;


UENUM()
enum class EFaction : uint8
{
	Rome	UMETA(DisplayName = "Rome"),
	Etruria		UMETA(DisplayName = "Etruria"),
	Carthage	UMETA(DisplayName = "Carthage")
};

USTRUCT()
struct FBaseFactionData
{
	GENERATED_BODY()
	
	FBaseFactionData()
	{
		FactionName = "NONE";
	}

	// Name
	FName FactionName{};

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
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
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

public:
	inline FName GetBaseFactionName() const { return FactionName; }
	
	// This is a virtual function that returns a reference to an FBaseFactionData object 
	virtual FBaseFactionData& GetRefToFactionData();
	
	
private:
	
	
protected:
	FName FactionName{};
	
	EFaction FactionType;

	// Objects by value of faction data structs
	FBaseFactionData BaseFactionData;
	
	
/****************************************************************/
	/* POPULATION */
	
public:
	// This is a virtual function that returns a reference to an FPopulation object
	virtual FPopulation& GetRefToPopulationData();
	
private:
	
protected:
	FPopulation Population;
	

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