// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/UI/BaseHUD.h"

ABaseHUD::ABaseHUD()
{
	
}

void ABaseHUD::BeginPlay()
{
	Super::BeginPlay();
	
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

void ABaseHUD::DrawHUD()
{
	Super::DrawHUD();
	
}
