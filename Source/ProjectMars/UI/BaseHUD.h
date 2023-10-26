// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ProjectMars/Economy/Data/EconomyData.h"
#include "BaseHUD.generated.h"

class UEconomyData;
class AArmy;

UCLASS()
class PROJECTMARS_API ABaseHUD : public AHUD
{
	GENERATED_BODY()

public:
	ABaseHUD();

	virtual void DrawHUD() override;

	UFUNCTION()
	void SetDateSuffix(const FString& SuffixVal);

	UFUNCTION()
	void InitialiseEconomyData(const UEconomyData* EconomyDataVar);

	UFUNCTION()
	static FVector2D GetMonitorResolution();

	UFUNCTION()
	static FVector2D GetViewportResolution();

	UFUNCTION()
	static FVector2D GetCenterOfScreen();
	
	UFUNCTION()
	FVector2D GetMousePosition2D() const;

	UFUNCTION()
	void DrawSelectionBox();

	UFUNCTION()
	void InitialisePointers();
	
	UFUNCTION()
	void DrawEconomyData(const UEconomyData* EconomyDataVar);
	
	UFUNCTION()
	void DrawTooltip();
	
	UFUNCTION()
	void GetActorsUnderSelectionBox();

	UFUNCTION()
	void DrawEventPopup();

	UFUNCTION()
	void MoveWidgetInViewportWithMouse(class UUserWidget* EventPopupWidgetToMove);

private:
	// Functions
	UFUNCTION()
	void DrawFPS();

	// Properties
	UPROPERTY(EditAnywhere)
	int32 FPSNum{};

	UPROPERTY(EditAnywhere)
	FString DateSuffix{};

	UPROPERTY(EditAnywhere)
	const UEconomyData* EconomyData{ nullptr };

	UPROPERTY(EditAnywhere)
	class AProjectMarsPlayer* Player{ nullptr };

	UPROPERTY(EditAnywhere)
	FVector2D InitialSelectionPoint{};
	
	UPROPERTY(EditAnywhere)
	FVector2D CurrentSelectionPoint{};
	
	UPROPERTY(EditAnywhere)
	bool bHasStartedSelecting;

	UPROPERTY(EditAnywhere, Category = "SelectionBox")
	FLinearColor SelectionBoxColor{};

	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<class UBaseGameplayWidget> BaseGameplayWidgetClass;

	UPROPERTY(EditAnywhere)
	class UBaseGameplayWidget* BaseGameplayWidget{ nullptr };

	UPROPERTY(EditAnywhere)
	class UEconomyWidget* EconomyWidget{ nullptr };
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UEconomyWidget> EconomyWidgetClass;
	
	UPROPERTY(EditAnywhere)
	class UEventPopupWidget* EventPopupWidget{ nullptr };

	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<class UEventPopupWidget> EventPopupWidgetClass;
	
	UPROPERTY(EditAnywhere)
	FVector2D StartingEventPopupPosition = FVector2D(660, 115);

	UPROPERTY(EditAnywhere)
	AArmy* ArmySelected{ nullptr };

	UPROPERTY(EditAnywhere)
	TArray<class AArmy*> ArmiesUnderSelectionBox;

	UPROPERTY(EditAnywhere)
	FVector2D CurrentEventPopupPos;

	UPROPERTY(EditAnywhere)
	FVector2D DistanceBetweenMouseAndLeftSideOfWidget;

protected:
	virtual void BeginPlay() override;
		
};