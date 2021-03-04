// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Controllers/BasePlayerController.h"

ABasePlayerController::ABasePlayerController()
{
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
}

void ABasePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}
