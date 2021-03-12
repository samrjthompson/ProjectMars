// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FactionBase.generated.h"

// Seem to have to forward declare the enums
enum class EFaction : uint8;
enum class ECultureGroup : uint8;
enum class ECulture : uint8;

struct FBaseFactionData;
struct FPopulation;


/*** CULTURE ***/



/*** POPULATION ***/
UENUM()
enum class EPopType
{
	Noble,
	Citizen,
	Freeman,
	Tribesman,
	Slave
};

USTRUCT()
struct FPopulation
{
	GENERATED_BODY()

	FPopulation();

	// General
	int32 TotalPopulation{};
	int32 TotalNoblePopulation{};
	int32 TotalCitizenPopulation{};
	int32 TotalFreemanPopulation{};
	int32 TotalTribesmanPopulation{};
	int32 TotalSlavePopulation{};

	// Growth
	float TotalGrowth{};
	float TotalShrink{};
	float NetGrowth{};

	float NobleGrowth{};
	float CitizenGrowth{};
	float FreemanGrowth{};
	float TribesmanGrowth{};
	float SlaveGrowth{};

	// Updates the grow as a percentage of each pop type
	void UpdateGrowthPerMonth();

	// Updates the total population each month after factoring in the growth that month
	void UpdateMonthlyPopulation();
};


/*** FACTION ***/
UENUM()
enum class EFaction : uint8
{
	Rome	UMETA(DisplayName = "Rome"),
	Etruria		UMETA(DisplayName = "Etruria"),
	Carthage	UMETA(DisplayName = "Carthage")
};


/*** ECONOMY ***/
USTRUCT()
struct FFactionEconomics
{
	GENERATED_BODY()

	FFactionEconomics();

	// GENERAL
	int32 StartingTreasury{};
	int32 Treasury{};
	float GrossIncome{};
	float NetIncome{};
	float Expenses{};

	// TAXES
	float TaxIncome{};
	
	UPROPERTY(EditAnywhere, Category = "Taxes")
	float NobleTaxRate{ 0.02f };
	
	UPROPERTY(EditAnywhere, Category = "Taxes")
	float CitizenTaxRate{ 0.01f };
	
	UPROPERTY(EditAnywhere, Category = "Taxes")
	float FreemanTaxRate{ 0.005f };
	
	UPROPERTY(EditAnywhere, Category = "Taxes")
	float TribesmanTaxRate{ 0.005f };

	// Function to calculate tax income
	void CollectTaxes(FPopulation& Obj);

	// TRADE
	float TotalValueOfExports{};
	float TotalValueOfImports{};

	// TRIBUTES
	float TributeIncome{};
	float OutgoingTributes{};

	// OTHER
	float LootingIncome{};

	
	// MAINTENANCE
	float ArmyMaintenance{};
	float FleetMaintenance{};
	float Wages{};
	float StateMaintenance{};
	float FortMaintenance{};


	/* --- ECONOMY --- */

	// Returns the net income of a player per month
	float GetNetIncome();

	// Returns the gross income of a player per month
	float GetGrossIncome();

	// Returns the total outgoings of a player per month
	float GetTotalOutgoings();

	// Adds the net income to the player's overall treasury on a monthly basis - can be negative or positive number
	void ApplyNetIncomeToTreasury();

	// If the player's treasury is less than 0, this will be true
	bool bHasADeficit;

	// If the player's income per month is less than 0, this will be true
	bool bHasNegativeIncome;

	// TAX

	void SetTaxIncome();
	
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

	inline FName GetBaseFactionName() const { return FactionName; }

	// This is a virtual function that returns a reference to an FBaseFactionData object 
	virtual FBaseFactionData& GetRefToFactionData();
	
	// This is a virtual function that returns a reference to an FFactionEconomics object
	virtual FFactionEconomics& GetRefToEconomicsData();

	// This is a virtual function that returns a reference to an FPopulation object
	virtual FPopulation& GetRefToPopulationData();

protected:
	FName FactionName{};

	EFaction FactionType;
	ECultureGroup CultureGroup;
	ECulture Culture;

	// Objects by value of faction data structs
	FBaseFactionData BaseFactionData;
	FFactionEconomics FactionEconomics;
	FPopulation Population;

private:
	
};