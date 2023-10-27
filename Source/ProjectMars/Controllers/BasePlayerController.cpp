// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"

#include "Components/TextBlock.h"
#include "Logging/StructuredLog.h"
#include "ProjectMars/Delegates/DelegateController.h"
#include "ProjectMars/Delegates/NationDelegateController.h"
#include "ProjectMars/Nation/Nation.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/UI/BaseHUD.h"
#include "ProjectMars/UI/Widgets/DevInfo/DevInfoWidget.h"

ABasePlayerController::ABasePlayerController()
{
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
	bEnableClickEvents = true;

	NationDelegateController = NewObject<UNationDelegateController>();

	// This is experimental, I think this sets a new HUD for the player
	if (false)
	{
		const TSubclassOf<ABaseHUD> ClientHUD;
		ClientSetHUD(ClientHUD);
	}
	
	bMyTurn = false;
	TurnNumber = 1;
}

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Enter", IE_Released, this, &ABasePlayerController::OnEnter);
	
	InputComponent->BindAction("LeftMouseClick", IE_Released, this, &ABasePlayerController::OnLMBClick);
	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &ABasePlayerController::OnRMBClick);

	// Player Pawn Movement
	InputComponent->BindAxis("MoveForward", this, &ABasePlayerController::MovePlayerPawnForwardOrBack);
	InputComponent->BindAxis("GameSpeed", this, &ABasePlayerController::MovePlayerPawnRightOrLeft);
}

void ABasePlayerController::SubscribeToDelegates(UDelegateController* DelegateControllerVar)
{
	DelegateControllerVar->OnChangeTurnOwner.AddDynamic(this, &ABasePlayerController::CheckForMyTurn);
	DelegateControllerVar->OnStartNewTurn.AddDynamic(this, &ABasePlayerController::StartNewTurn);
}

ABasePlayerController* ABasePlayerController::SetDelegateController(UDelegateController* DelegateControllerVar)
{
	DelegateController = DelegateControllerVar;
	return this;
}

ABasePlayerController* ABasePlayerController::SetNation(UNation* NationVar)
{
	Nation = NationVar;
	Nation->SetFactionTag("ROM");
	UE_LOGFMT(LogTemp, Warning, "Player nation: ROM");
	return this;
}

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
}

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitialisePointers();
}

void ABasePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ABasePlayerController::OnRMBClick()
{
	PlayerPawn->IssueMoveArmyOrder();
}

void ABasePlayerController::OnEnter()
{
	// TODO: Add if-statement to check if player is owner of turn
	DelegateController->OnEndTurn.Broadcast();
}

void ABasePlayerController::InitialisePointers()
{
	PlayerPawn = Cast<AProjectMarsPlayer>(GetPawn());
	HUD = Cast<ABaseHUD>(GetHUD());
}

void ABasePlayerController::CheckForMyTurn(const FString& CurrentTurnOwnerTag)
{
	if (!Nation)
	{
		UE_LOGFMT(LogTemp, Error, "Nation is null");
	} 

	const UDevInfoWidget* Widget = HUD->GetDevInfoWidget();
	Widget->CurrentTurnOwnerText->SetText(FText::FromString(CurrentTurnOwnerTag));
	if (CurrentTurnOwnerTag == Nation->GetFactionTag())
	{
		bMyTurn = true;
		return;
	}
	bMyTurn = false;
}

void ABasePlayerController::StartNewTurn(const int32 TurnNumberVar)
{
	TurnNumber = TurnNumberVar;
	const UDevInfoWidget* Widget = HUD->GetDevInfoWidget();
	Widget->TurnNumberText->SetText(FText::AsNumber(TurnNumberVar));
}
