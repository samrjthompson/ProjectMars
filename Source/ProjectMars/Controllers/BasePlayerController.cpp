// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Controllers/BasePlayerController.h"


#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/UI/BaseHUD.h"

ABasePlayerController::ABasePlayerController()
{
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
	bGameIsPaused = true;
}

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &ABasePlayerController::SelectionPressed);
	InputComponent->BindAction("LeftMouseClick", IE_Released, this, &ABasePlayerController::SelectionReleased);
	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &ABasePlayerController::RMBPressed);
	InputComponent->BindAction("PauseGame", IE_Pressed, this, &ABasePlayerController::PauseGame);
}

void ABasePlayerController::PauseGame()
{
	switch (bGameIsPaused)
	{
		case true : bGameIsPaused = false;
		break;

		case false : bGameIsPaused = true;
		break;
	}
}

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = Cast<ABaseHUD>(GetHUD());
}

void ABasePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

void ABasePlayerController::SelectionPressed()
{
	if(HUD)
	{
		HUD->bHasStartedSelecting = true;
		
		HUD->InitialSelectionPoint = HUD->GetMousePosition2D();
	}
}

void ABasePlayerController::SelectionReleased()
{
	if(HUD)
	{
		HUD->bHasStartedSelecting = false;
	}
}

void ABasePlayerController::RMBPressed()
{
	OnRMBPressed.Broadcast();
}