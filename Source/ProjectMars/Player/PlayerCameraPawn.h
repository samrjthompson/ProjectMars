// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCameraPawn.generated.h"

enum class EFaction : uint8;
struct FBaseFactionData;
struct FFactionEconomics;

USTRUCT()
struct FPlayerEconomy
{
	GENERATED_BODY()

	FPlayerEconomy()
	{
		StartingTreasury = 5000.00f;
		Treasury = StartingTreasury;
	}

	// Economy
	float StartingTreasury{};
	float Treasury{};
	float GrossIncome{};
	float NetIncome{};
	float Expenses{};
	float TaxIncome{};
	float TotalValueOfExports{};
	float TotalValueOfImports{};
	float LootingIncome{};
	float TributeIncome{};
	float StateMaintenance{};
	float FortMaintenance{};
	float OutgoingTributes{};

	// Maintenance
	float ArmyMaintenance{};
	float FleetMaintenance{};
	float Wages{};

};

UCLASS()
class PROJECTMARS_API APlayerCameraPawn : public APawn
{
	friend class ABaseHUD;
	
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCameraPawn();

	UPROPERTY(EditAnywhere)
	class USceneComponent* RootComp{ nullptr };

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArmComp{ nullptr };

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera{ nullptr };

	TSubclassOf<class URomeFaction> RomeClass;
	
	void SetTreasury();	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Cache a ref to FPlayerEconomy
	FPlayerEconomy PlayerEconomy;
		
	FBaseFactionData* BaseFactionData{ nullptr };
	FFactionEconomics* FactionEconomics{ nullptr };

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// The faction the player will be playing as
	UPROPERTY()
	class UFactionBase* PlayerAssignedFaction{ nullptr };

private:
	void PawnMovement(float DeltaTime);

	void UpdatePlayerFactionInfo();
	
	FVector MovementDirection{};

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed;

	void MoveForward(float Val);	
	void MoveRight(float Val);

	void ChooseRome();
	void ChooseEtruria();
	void ChooseCarthage();

	// Sets the player's faction 
	void InitialisePlayerFaction(const EFaction Faction);

	bool bHasChosenFaction;

	// Initialises a pointer (stored in the ABaseHUD class) to a faction class object
	void InitialiseHUD(class UFactionBase* FactionBase);

	UPROPERTY()
	class ABasePlayerController* BasePlayerController{ nullptr };

	UPROPERTY()
	class ABaseHUD* BaseHUD{ nullptr };

	
	// ECONOMY

	// Updates the player income each month
	void UpdatePlayerIncome();

	void AddMoney();

/* --- TIME --- */

	// The last time an update occured in seconds
	float LastUpdateCheckTime;

	// Amount in seconds we want to update our player's faction info
	float UpdateCheckFrequency;
};