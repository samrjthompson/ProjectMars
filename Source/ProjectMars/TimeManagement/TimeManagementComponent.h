// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "TimeManagementComponent.generated.h"

class AProjectMarsPlayer;
class ABasePlayerController;
class ABaseHUD;
class UPlayerManagerComponent;

UENUM()
enum class EEra
{
	BCE,
	CE,

	MAX
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTMARS_API UTimeManagementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTimeManagementComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Initialises CurrentMonth depending on the current MonthIndex
	UFUNCTION()
	void UpdateMonth();

	// Tick function that manages how many seconds it takes for a month to pass - the seconds are determined by th UpdateCheckFrequency variable
	UFUNCTION()
	void UpdateGameTime();

	UFUNCTION()
	int32 GetMaxDaysInMonth() const;

	UFUNCTION()
	float GetTickRate() const;

	UFUNCTION()
	int32 GetCurrentDay() const;

	UFUNCTION()
	FString ConvertCurrentMonthToString() const;

	UFUNCTION()
	int32 GetCurrentYear() const;

	UFUNCTION()
	void CalculateTickRate();

	UFUNCTION()
	void CalculateCurrentDay();

	UFUNCTION()
	void CalculateMaxDaysInMonth();

	UFUNCTION()
	static double GetTimeSince(double StartTime);

	UFUNCTION()
	AProjectMarsPlayer* GetPlayer() const;

	UFUNCTION()
	void SetPlayer(AProjectMarsPlayer* PlayerPtr);

	UFUNCTION()
	ABasePlayerController* GetPlayerController() const;

	UFUNCTION()
	void SetPlayerController(ABasePlayerController* PlayerControllerVal);

	UFUNCTION()
	ABaseHUD* GetBaseHUD() const;

	UFUNCTION()
	void SetBaseHUD(ABaseHUD* BaseHUDVal);
	
	UFUNCTION()
	void LogEveryXSeconds(double Val);

	UFUNCTION()
	void InitialiseRefs();

	UFUNCTION()
	void SetLastUpdateCheckTime(double Time);

	UFUNCTION()
	void SetUpdateCheckFrequency(float Freq);

	UFUNCTION()
	UPlayerManagerComponent* GetPlayerManagerComponent() const;

	UFUNCTION()
	int32 GetCurrentDisplayDay() const;

	UFUNCTION()
	int32 GetCurrentDisplayYear() const;
	
protected:	
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	bool bGameHasStarted = false;
	
	// The last time an update occurred in seconds
	UPROPERTY()
	double LastUpdateCheckTime{};

	// Real world seconds per month
	UPROPERTY(EditAnywhere)
	float UpdateCheckFrequency{};
	
	enum EMonthOfYear CurrentMonth{};

	UPROPERTY()
	int32 MonthIndex{};

	UPROPERTY()
	int32 MaxDaysInMonth{};

	UPROPERTY()
	int32 CurrentDay{};

	// Display day so that an incorrect day isn't shown to user - i.e., 32nd of July
	UPROPERTY()
	int32 CurrentDisplayDay{};

	UPROPERTY()
	int32 PreviousDay{};

	UPROPERTY()
	float DaysPerTick{};

	UPROPERTY()
	double LastTickCheck{};

	UPROPERTY()
	float CurrentTick{};

	UPROPERTY()
	float TickRate{};

	UPROPERTY()
	float TicksPerMonth{};

	UPROPERTY()
	int32 CurrentYear{};

	// Display year so that an incorrect year isn't shown to user - i.e., 0 BCE
	UPROPERTY()
	int32 CurrentDisplayYear{};

	UPROPERTY()
	int32 StartYear{};

	UPROPERTY()
	int32 MonthsInGame{};

	UPROPERTY()
	double LogCheck{};

	EEra CurrentEra{};
	
	

	UPROPERTY()
	class AProjectMarsPlayer* Player{ nullptr };

	UPROPERTY()
	class ABasePlayerController* PlayerController{ nullptr };

	UPROPERTY()
	class AMarsGameStateBase* GameState{ nullptr };

	UPROPERTY()
	class ABaseHUD* BaseHUD{ nullptr };

	UPROPERTY()
	class UDelegateController* DelegateController{ nullptr };

	UPROPERTY()
	class UPlayerManagerComponent* PlayerManagerComponent{ nullptr };
};
