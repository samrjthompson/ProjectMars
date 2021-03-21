// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BaseHUD.generated.h"

enum class EMonthOfYear;

class AFactionBase;

UCLASS()
class PROJECTMARS_API ABaseHUD : public AHUD
{
	GENERATED_BODY()

public:
	ABaseHUD();

	virtual void DrawHUD() override;

	FString HUDName = "Bob";

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	class AProjectMarsPlayer* Player{ nullptr };

public:
	static FVector2D GetMonitorResolution();
	static FVector2D GetViewportResolution();
	static FVector2D GetCenterOfScreen();
	
	FVector2D GetMousePosition2D() const;

	FVector2D InitialSelectionPoint{};
	FVector2D CurrentSelectionPoint{};

	void DrawSelectionBox();
	bool bHasStartedSelecting;

	UPROPERTY(EditAnywhere, Category = "SelectionBox")
	FLinearColor SelectionBoxColor{};

/* --- WIDGETS --- */
public:
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<class UBaseGameplayWidget> BaseGameplayWidgetClass;
	
	UPROPERTY()
	class UBaseGameplayWidget* BaseGameplayWidget{ nullptr };
	
	struct FFaction* FactionBase{ nullptr };

	void InitialiseFactionBase(struct FFaction* InitFaction);

	virtual void InitialisePointers();

	virtual ABaseHUD* GetRefToBaseHUD();

/* --- ECONOMY --- */
	void DrawPlayerTreasury();
	

/* --- TIME ---*/

	void DrawDate();
	FString DateSuffix{};

/* --- FPS --- */
	void DrawFPS();
	int32 FPSNum{};

/* --- CHOOSE FACTION LEVEL --- */
	// void DrawChooseFaction();

	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<class UChooseFactionWidget> ChooseFactionWidgetClass;

	UPROPERTY()
	class UChooseFactionWidget* ChooseFactionWidget{ nullptr };

	UFUNCTION()
	void DrawMainGameUI();

	
	/***********************************************************************/

	/* DRAW TOOLTIP */

	UPROPERTY(EditAnywhere)
	class UEconomyWidget* EconomyWidget{ nullptr };
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UEconomyWidget> EconomyWidgetClass;

	void DrawTooltip();

/////////////////////////////////////////////////////////////////////
// POPULATION

	void DrawPopulationNum();
};