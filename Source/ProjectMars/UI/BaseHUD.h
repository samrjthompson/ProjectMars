// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ProjectMars/Factions/FactionBase.h"

#include "BaseHUD.generated.h"

UENUM()
enum EMonth
{
	Jan = 1,
	Feb = 2,
	Mar = 3,
	Apr = 4,
	May = 5,
	Jun = 6,
	Jul = 7,
	Aug = 8,
	Sept = 9,
	Oct = 10,
	Nov = 11,
	Dec = 12
};

enum EMonth;

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
	class APlayerCameraPawn* Player{ nullptr };

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

	UPROPERTY()
	UFactionBase* FactionBase{ nullptr };

	void InitialiseFactionBase(UFactionBase* InitFactionBase);

/* --- ECONOMY --- */
	void DrawPlayerTreasury();
	

/* --- TIME ---*/

	void DrawDate();

	// Array to store Month enums
	TArray<EMonth> MonthArray[12];
};
