// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MarsGameStateBase.generated.h"

class APlayerCameraPawn;

enum class EMonthOfYear;

struct FCampaignDateTime;

UCLASS()
class PROJECTMARS_API AMarsGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMarsGameStateBase();

	virtual void BeginPlay() override;

	// Function that initialises the pointers via the player class
	void InitialiseReferences(APlayerCameraPawn* InitPlayer);

protected:
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY()
	class ABasePlayerController* PlayerController{ nullptr };

	UPROPERTY()
	APlayerCameraPawn* Player{ nullptr };

	UPROPERTY()
	class ABaseHUD* BaseHUD{ nullptr };

	
/* --- TIME --- */
public:
	// 
	void UpdateMonth();

	void UpdateGameTime();

	FCampaignDateTime* CampaignDateTime;

	// The last time an update occured in seconds
	float LastUpdateCheckTime;

	// Amount in seconds we want to update our player's faction info
	float UpdateCheckFrequency;
	
protected:
	
private:
	// Copy of EMonthOfYear obj so that can evaluate an if statement (i.e., if(CurrentMonth == EMonthOfYear::January) { // Do something }).
	EMonthOfYear CurrentMonth;

	// Storing the month number to be used in a switch statement
	int32 MonthIndex;

};
