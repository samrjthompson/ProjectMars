// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectMars/Controllers/BasePlayerController.h"


#include "Logging/StructuredLog.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/UI/BaseHUD.h"

void ABasePlayerController::MovePlayerPawnForwardOrBack(float Val)
{
	if (!PlayerPawn)
	{
		UE_LOGFMT(LogTemp, Error, "Player pawn is null");
		return;
	}
	PlayerPawn->MoveForwardOrBack(Val);
}

void ABasePlayerController::MovePlayerPawnRightOrLeft(float Val)
{
	if (!PlayerPawn)
	{
		UE_LOGFMT(LogTemp, Error, "Player pawn is null");
		return;
	}
	PlayerPawn->MoveRightOrLeft(Val);
}

void ABasePlayerController::OnLMBClick()
{
	FHitResult LeftClick;
	if (GetHitResultUnderCursor(ECC_Visibility, false, LeftClick))
	{
		PlayerPawn->FilterActorClickedOn(LeftClick.GetActor());
	}
	if(HUD)
	{
		HUD->bHasStartedSelecting = false;
	}
}

ABasePlayerController::ABasePlayerController()
{
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
	bGameIsPaused = true;
	bEnableClickEvents = true;

	// This is experimental, I think this sets a new HUD for the player
	if (false)
	{
		const TSubclassOf<ABaseHUD> ClientHUD;
		ClientSetHUD(ClientHUD);
	}
}

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &ABasePlayerController::SelectionPressed);
	InputComponent->BindAction("LeftMouseClick", IE_Released, this, &ABasePlayerController::OnLMBClick);
	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &ABasePlayerController::RMBPressed);
	InputComponent->BindAction("PauseGame", IE_Pressed, this, &ABasePlayerController::PauseGame);

	// Player Pawn Movement
	InputComponent->BindAxis("MoveForward", this, &ABasePlayerController::MovePlayerPawnForwardOrBack);
	InputComponent->BindAxis("GameSpeed", this, &ABasePlayerController::MovePlayerPawnRightOrLeft);
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
		HUD->ArmiesUnderSelectionBox.Empty();
		HUD->ArmySelected = nullptr;
		HUD->bHasStartedSelecting = true;
		
		HUD->InitialSelectionPoint = HUD->GetMousePosition2D();
	}
}

void ABasePlayerController::SelectionReleased()
{

}

void ABasePlayerController::RMBPressed()
{
	OnRMBPressed.Broadcast();
}