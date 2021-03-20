// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ProjectMars/Factions/FactionBase.h"

#include "ProjectMarsPlayer.generated.h"

enum class EFactionName : uint8;
struct FFaction;
struct FFactionEconomics;
struct FCampaignDateTime;

UENUM()
enum ETestType
{
	Test1,
	Test2,
	Test3,

	MAX
};


USTRUCT()
struct FPlayerEconomy
{
	GENERATED_BODY()

	FPlayerEconomy()
	{
		StartingTreasury = 5000;
		Treasury = StartingTreasury;
	}

	// Economy
	int32 StartingTreasury{};
	int32 Treasury{};
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
class PROJECTMARS_API AProjectMarsPlayer : public APawn
{
	friend class ABaseHUD;
	friend class AMarsGameStateBase;
	
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AProjectMarsPlayer();

	//FOnFactionChosenByPlayer OnFactionChosenByPlayer;

	UPROPERTY(EditAnywhere)
	class USceneComponent* RootComp{ nullptr };

	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArmComp{ nullptr };

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Faction")
	class AFactionBase* FactionBase{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Culture")
	class ACultureBase* CultureBase{ nullptr };

	TSubclassOf<class ARomeFaction> RomeClass;
	
	void SetTreasury();

	FString CurrentLevel{};

	void InitialiseAIComponents(AProjectMarsPlayer* AIPlayer);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FPlayerEconomy PlayerEconomy;
		
	FFaction* BaseFactionData{ nullptr };
	FFactionEconomics* FactionEconomics{ nullptr };

	FFaction* FactionPtr{ nullptr };

	UPROPERTY()
	class AMarsGameStateBase* MarsGameStateBase{ nullptr };

	/* Function that calls the InitialiseReferences function in the GameState class and passes 'this' as the arg
	 * so that we can initialise a pointer to the player pointer from GameState class. */
	void InitialiseGameStateRefs();

	void InitialisePlayerController();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// The faction the player will be playing as
	struct FFaction* PlayerFaction{ nullptr };

private:
	void PawnMovement(float DeltaTime);

	FVector MovementDirection{};

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed;

	void MoveForward(float Val);	
	void MoveRight(float Val);

	UFUNCTION()
	void ChooseRome();
	
	UFUNCTION()
	void ChooseEtruria();

	UFUNCTION()
	void ChooseCarthage();

	// Sets the player's faction by creating a NewObject based off the faction that was chosen by the player
	void InitialisePlayerFaction(const EFactionName& Faction);

	// Initialises a pointer (stored in the ABaseHUD class) to a faction class object
	void InitialiseHUD();

	//TSharedPtr<class ABasePlayerController> BasePlayerController;

	UPROPERTY()
	class ABasePlayerController* BasePlayerController{ nullptr };

	UPROPERTY()
	class ABaseHUD* BaseHUD{ nullptr };

public:
	void UpdatePlayerFactionInfo();

	bool bHasChosenFaction;

	
	// ECONOMY

	// Updates the player income each month
	void UpdatePlayerIncome();

	void AddMoney();
	

	// TIME

	FCampaignDateTime* CampaignDateTimePtr;
	

	void UpdateGameSpeed(float Val);

	bool bHasSetTreasury;

	EMonthOfYear CurrentMonth;

	int32 MonthIndex;
	
	
	// POPULATION
	
	// Updates player population data every month
	void UpdatePlayerPopulationData();

};