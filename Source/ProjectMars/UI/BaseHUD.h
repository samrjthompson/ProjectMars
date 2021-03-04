// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BaseHUD.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMARS_API ABaseHUD : public AHUD
{
	GENERATED_BODY()

public:
	ABaseHUD();

	virtual void DrawHUD() override;

protected:
	virtual void BeginPlay() override;

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
};
