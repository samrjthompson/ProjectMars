// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/UI/BaseHUD.h"

#include "Engine.h"
#include "Components/TextBlock.h"
#include "ProjectMars/Framework/MarsGameStateBase.h"
#include "ProjectMars/Player/PlayerCameraPawn.h"
#include "ProjectMars/UI/Widgets/BaseGameplayWidget.h"

#define OUT

ABaseHUD::ABaseHUD()
{
	bHasStartedSelecting = false;
	SelectionBoxColor = FLinearColor(0.f, 1.f, 0.2f, 0.15f);
}

void ABaseHUD::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<APlayerCameraPawn>(GetOwningPlayerController()->GetPawn());

	BaseGameplayWidget = CreateWidget<UBaseGameplayWidget>(GetOwningPlayerController(), BaseGameplayWidgetClass);
	if(BaseGameplayWidget)
	{
		BaseGameplayWidget->AddToViewport();
		UE_LOG(LogTemp, Warning, TEXT("BaseGameplayWidget is valid"));
	}
}

void ABaseHUD::DrawHUD()
{
	Super::DrawHUD();

	if(bHasStartedSelecting)
	{
		CurrentSelectionPoint = GetMousePosition2D();
		DrawSelectionBox();
	}

	DrawPlayerTreasury();

	DrawDate();
}

FVector2D ABaseHUD::GetMonitorResolution()
{
	FVector2D MonitorRes{};

	MonitorRes.X = GSystemResolution.ResX;
	MonitorRes.Y = GSystemResolution.ResY;
	
	return MonitorRes;
}

FVector2D ABaseHUD::GetViewportResolution()
{
	FVector2D ViewportSize{};
	
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(OUT ViewportSize);		
	}

	return ViewportSize;
}

FVector2D ABaseHUD::GetCenterOfScreen()
{
	FVector2D ScreenCentre{};

	ScreenCentre.X = GetViewportResolution().X / 2;
	ScreenCentre.Y = GetViewportResolution().Y / 2;
	
	return ScreenCentre;
}

FVector2D ABaseHUD::GetMousePosition2D() const
{
	FVector2D MousePos{};
	
	GetOwningPlayerController()->GetMousePosition(OUT MousePos.X, OUT MousePos.Y);

	return MousePos;
}

void ABaseHUD::DrawSelectionBox()
{
	DrawRect(SelectionBoxColor, InitialSelectionPoint.X, InitialSelectionPoint.Y,
		CurrentSelectionPoint.X - InitialSelectionPoint.X, CurrentSelectionPoint.Y - InitialSelectionPoint.Y);
}

void ABaseHUD::InitialiseFactionBase(UFactionBase* InitFactionBase)
{
	FactionBase = InitFactionBase;
}

void ABaseHUD::DrawPlayerTreasury()
{
	if(BaseGameplayWidget && Player)
	{
		BaseGameplayWidget->EconomyText->SetText(FText::FromString(FString::SanitizeFloat(Player->PlayerEconomy.Treasury)));
	}
}

void ABaseHUD::DrawDate()
{	
	if(BaseGameplayWidget && Player)
	{
		BaseGameplayWidget->DayText->SetText(FText::AsNumber(Player->MarsGameStateBase->GetCurrentDay()));
		BaseGameplayWidget->MonthText->SetText(FText::FromString(Player->MarsGameStateBase->GetCurrentMonthName()));
		BaseGameplayWidget->YearText->SetText(FText::AsNumber(Player->MarsGameStateBase->GetCurrentYear()));
	}
}