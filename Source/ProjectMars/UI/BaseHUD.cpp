// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseHUD.h"

#include "Engine.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Logging/StructuredLog.h"
#include "ProjectMars/Controllers/BasePlayerController.h"
#include "ProjectMars/Delegates/DelegateController.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/UI/Widgets/BaseGameplayWidget.h"
#include "ProjectMars/UI/Widgets/DevInfo/DevInfoWidget.h"
#include "Widgets/EconomyWidget.h"
#include "Widgets/Events/EventPopupWidget.h"
#include "ProjectMars/Military/Army.h"
#include "ProjectMars/Economy/Data/EconomyData.h"
#include "Widgets/DevInfo/StartButtonWidget.h"

#define OUT

ABaseHUD::ABaseHUD()
{
	bHasStartedSelecting = false;
	SelectionBoxColor = FLinearColor(0.f, 1.f, 0.2f, 0.15f);

	DateSuffix = "BCE";
	CurrentSeason = "NO_SEASON_SET";
}

void ABaseHUD::BeginPlay()
{
	Super::BeginPlay();
	
	InitialisePointers();
	
	DevInfoWidget->TurnNumberText->SetText(FText::AsNumber(1));
	DevInfoWidget->CurrentTurnOwnerText->SetText(FText::FromString("ROM"));
	DevInfoWidget->AddToViewport();
	
	StartButtonWidget->StartText->SetText(FText::FromString("START"));
	StartButtonWidget->StartButton->OnReleased.AddDynamic(this, &ABaseHUD::BroadcastStartButton);
	StartButtonWidget->AddToViewport();
}

void ABaseHUD::DrawHUD()
{
	Super::DrawHUD();

	/*if(bHasStartedSelecting)
	{
		CurrentSelectionPoint = GetMousePosition2D();
		DrawSelectionBox();
	}*/
	
	//DrawFPS();
	//DrawEconomyData(EconomyData);
	DrawDevInfo();

	/*if(EventPopupWidget && EventPopupWidget->DecisionButton)
	{
		if(EventPopupWidget->DecisionButton->IsPressed())
		{
			EventPopupWidget->CloseEventPopup();
		}
	}*/

	//MoveWidgetInViewportWithMouse(EventPopupWidget);
}

void ABaseHUD::SetDateSuffix(const FString& SuffixVal)
{
	DateSuffix = SuffixVal;
}

void ABaseHUD::InitialiseEconomyData(const UEconomyData* EconomyDataVar)
{
	EconomyData = EconomyDataVar;
}

FVector2D ABaseHUD::GetMonitorResolution()
{
	FVector2D MonitorRes;

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
	FVector2D ScreenCentre;

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

	GetActorsInSelectionRectangle<AArmy>(InitialSelectionPoint, CurrentSelectionPoint, ArmiesUnderSelectionBox, false);

	if (ArmiesUnderSelectionBox.IsValidIndex(0))
	{
		ArmySelected = ArmiesUnderSelectionBox[0];
		if (ArmySelected)
		{
			// Do something with army selected
		}
	}
}

void ABaseHUD::InitialisePointers()
{
	Player = Cast<AProjectMarsPlayer>(GetOwningPlayerController()->GetPawn());
	
	BaseGameplayWidget = CreateWidget<UBaseGameplayWidget>(GetOwningPlayerController(), BaseGameplayWidgetClass);
	EconomyWidget = CreateWidget<UEconomyWidget>(GetOwningPlayerController(), EconomyWidgetClass);
	EventPopupWidget = CreateWidget<UEventPopupWidget>(GetOwningPlayerController(), EventPopupWidgetClass);
	DevInfoWidget = CreateWidget<UDevInfoWidget>(GetOwningPlayerController(), DevInfoWidgetClass);
	StartButtonWidget = CreateWidget<UStartButtonWidget>(GetOwningPlayerController(), StartButtonWidgetClass);
}

void ABaseHUD::DrawEconomyData(const UEconomyData* EconomyDataVar)
{
	if (!BaseGameplayWidget)
	{
		UE_LOGFMT(LogTemp, Error, "BaseGameplayeWidget is null!");
	}
	
	/*FString TreasuryText = "Treasury: " + FString::FromInt(EconomyDataVar->GetTreasury());
	FString ExpensesText = "Expenses: " + FString::FromInt(EconomyDataVar->GetExpenses());
	FString GrossIncomeText = "GrossIncome: " + FString::FromInt(EconomyDataVar->GetSumOfIncome());
	FString NetIncomeText = "NetIncome: " + FString::FromInt(EconomyDataVar->GetNetIncome());
	
	BaseGameplayWidget->Treasury->SetText(FText::FromString(TreasuryText));
	BaseGameplayWidget->Expenses->SetText(FText::FromString(ExpensesText));
	BaseGameplayWidget->GrossIncome->SetText(FText::FromString(GrossIncomeText));
	BaseGameplayWidget->NetIncome->SetText(FText::FromString(NetIncomeText));*/
}

void ABaseHUD::DrawFPS()
{
	if(BaseGameplayWidget)
	{
		BaseGameplayWidget->FPSText->SetText(FText::AsNumber(FPSNum));
	}
}

void ABaseHUD::DrawDevInfo()
{
	if (!DevInfoWidget)
	{
		UE_LOGFMT(LogTemp, Error, "Dev Info Widget is null");
		return;
	}
	// DevInfoWidget->TurnNumberText->SetText(FText::FromString("Turn Number Text"));
	DevInfoWidget->SeasonText->SetText(FText::FromString(CurrentSeason));
	DevInfoWidget->YearText->SetText(FText::FromString("Year Text"));
	// DevInfoWidget->CurrentTurnOwnerText->SetText(FText::FromString("Current Turn Owner Text"));
}

void ABaseHUD::DrawTooltip()
{
	if (!BaseGameplayWidget) return;

	int32 CurrentCount = 0;

	// EconomyWidget->RemoveFromParent();

	if (!BaseGameplayWidget->EconomyText->IsHovered()) { return; }


	/*DrawRect(FLinearColor(0, 0, 0, 0.75), GetMousePosition2D().X + 20, GetMousePosition2D().Y + 20,
		GetMousePosition2D().X + 100, GetMousePosition2D().Y + 50);	*/

	BaseGameplayWidget->SetToolTip(EconomyWidget);
}

void ABaseHUD::DrawEventPopup()
{
	if (!EventPopupWidget) return;

	EventPopupWidget->SetPositionInViewport(StartingEventPopupPosition);
	EventPopupWidget->AddToViewport();
}

void ABaseHUD::MoveWidgetInViewportWithMouse(UUserWidget* EventPopupWidgetToMove)
{
	// TODO: Currently requires a double click if we use the left mouse button rather than single click.
	// TODO: Also clicks on whatever is behind the widget as well as the widget.
	
	if (!EventPopupWidgetToMove) { return; }

	// EventPopupWidgetToMove->bIsFocusable = true;

	if(EventPopupWidgetToMove->IsHovered() && !GetOwningPlayerController()->IsInputKeyDown(EKeys::LeftAlt))
	{
		DistanceBetweenMouseAndLeftSideOfWidget = GetMousePosition2D() - CurrentEventPopupPos;
	}

	if(EventPopupWidgetToMove->IsHovered() && GetOwningPlayerController()->IsInputKeyDown(EKeys::LeftAlt))
	{
		CurrentEventPopupPos = GetMousePosition2D() - DistanceBetweenMouseAndLeftSideOfWidget;
		EventPopupWidgetToMove->SetPositionInViewport(CurrentEventPopupPos);
	}
}

UDevInfoWidget* ABaseHUD::GetDevInfoWidget() const
{
	return DevInfoWidget;
}

void ABaseHUD::BroadcastStartButton()
{
	StartButtonWidget->RemoveFromParent();
	ABasePlayerController* Controller = Cast<ABasePlayerController>(GetOwningPlayerController());
	Controller->StartGame();
}

void ABaseHUD::SubscribeToEvents(UDelegateController* DelegateControllerVar)
{
	DelegateControllerVar->OnNewSeason.AddDynamic(this, &ABaseHUD::UpdateSeasonText);
}

ABaseHUD* ABaseHUD::SetDelegateController(UDelegateController* DelegateControllerVar)
{
	DelegateController = DelegateControllerVar;
	return this;
}

void ABaseHUD::UpdateSeasonText(const FString& NewSeasonVar)
{
	CurrentSeason = NewSeasonVar;
}

void ABaseHUD::GetActorsUnderSelectionBox()
{
	
}
