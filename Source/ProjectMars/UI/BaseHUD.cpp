// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseHUD.h"

#include "Engine.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "ProjectMars/Components/Time/TimeManagementComponent.h"
#include "ProjectMars/Framework/MarsGameStateBase.h"
#include "ProjectMars/Player/ProjectMarsPlayer.h"
#include "ProjectMars/UI/Widgets/BaseGameplayWidget.h"
#include "Widgets/ChooseFactionWidget.h"
#include "Widgets/EconomyWidget.h"
#include "Widgets/Events/EventPopupWidget.h"
#include "ProjectMars/Military/Army.h"

#define OUT

ABaseHUD::ABaseHUD()
{
	bHasStartedSelecting = false;
	SelectionBoxColor = FLinearColor(0.f, 1.f, 0.2f, 0.15f);

	DateSuffix = "BCE";
}

void ABaseHUD::BeginPlay()
{
	Super::BeginPlay();
	
	InitialisePointers();

	CurrentEventPopupPos = StartingEventPopupPosition;
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
	DrawPopulationNum();
	DrawDate();
	DrawFPS();
	DrawTooltip();

	if(EventPopupWidget && EventPopupWidget->DecisionButton)
	{
		if(EventPopupWidget->DecisionButton->IsPressed())
		{
			EventPopupWidget->CloseEventPopup();
		}
	}

	MoveWidgetInViewportWithMouse(EventPopupWidget);
}

void ABaseHUD::SetDateSuffix(const FString& SuffixVal)
{
	DateSuffix = SuffixVal;
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

	GetActorsInSelectionRectangle<AArmy>(InitialSelectionPoint, CurrentSelectionPoint, ArmiesUnderSelectionBox, false);

	if (ArmiesUnderSelectionBox.IsValidIndex(0))
	{
		ArmySelected = ArmiesUnderSelectionBox[0];
		if (ArmySelected)
		{
			
		}
	}
}

void ABaseHUD::InitialiseFactionBase(FFaction* InitFaction)
{
	FactionBase = InitFaction;
}

void ABaseHUD::InitialisePointers()
{
	Player = Cast<AProjectMarsPlayer>(GetOwningPlayerController()->GetPawn());

	BaseGameplayWidget = CreateWidget<UBaseGameplayWidget>(GetOwningPlayerController(), BaseGameplayWidgetClass);

	ChooseFactionWidget = CreateWidget<UChooseFactionWidget>(GetOwningPlayerController(), ChooseFactionWidgetClass);
	if (ChooseFactionWidget)
	{
		ChooseFactionWidget->AddToViewport();
		ChooseFactionWidget->OnChooseFaction.AddDynamic(this, &ABaseHUD::DrawMainGameUI);
	}

	EconomyWidget = CreateWidget<UEconomyWidget>(GetOwningPlayerController(), EconomyWidgetClass);

	EventPopupWidget = CreateWidget<UEventPopupWidget>(GetOwningPlayerController(), EventPopupWidgetClass);
}

ABaseHUD* ABaseHUD::GetRefToBaseHUD()
{
	return this;
}

void ABaseHUD::DrawPlayerTreasury()
{
	if(BaseGameplayWidget && Player && Player->PlayerFaction)
	{
		//BaseGameplayWidget->EconomyText->SetText(FText::FromString(FString::SanitizeFloat(Player->PlayerEconomy.Treasury)));
		//BaseGameplayWidget->EconomyText->SetText(FText::AsNumber(Player->PlayerFaction->Economics.Treasury));
	}
}

void ABaseHUD::DrawDate()
{	
	if(BaseGameplayWidget && Player && Player->MarsGameStateBase)
	{
		const UTimeManagementComponent* TimeManagementComponent = Player->GetMarsGameStateBase()->GetTimeManagementComponent();
		if(!TimeManagementComponent) return;
		
		BaseGameplayWidget->DayText->SetText(FText::AsNumber(TimeManagementComponent->GetCurrentDisplayDay()));
		BaseGameplayWidget->MonthText->SetText(FText::FromString(TimeManagementComponent->ConvertCurrentMonthToString()));
		BaseGameplayWidget->YearText->SetText(FText::AsNumber(TimeManagementComponent->GetCurrentDisplayYear()));
		
		BaseGameplayWidget->DateSuffixText->SetText(FText::FromString(DateSuffix));
	}
}

void ABaseHUD::DrawFPS()
{
	if(BaseGameplayWidget)
	{
		BaseGameplayWidget->FPSText->SetText(FText::AsNumber(FPSNum));
	}
}

// TODO: Currently set up so that any button we click will choose Rome - need to make out faction choice relate to the button we press
void ABaseHUD::DrawMainGameUI()
{
	if(ChooseFactionWidget && BaseGameplayWidget && Player)
	{		
		if(ChooseFactionWidget->RomeButton->IsHovered())
		{
			Player->ChooseRome();

			ChooseFactionWidget->RemoveFromParent();
			BaseGameplayWidget->AddToViewport();
		}
		if(ChooseFactionWidget->EtruriaButton->IsHovered())
		{
			Player->ChooseEtruria();
			ChooseFactionWidget->RemoveFromParent();
			BaseGameplayWidget->AddToViewport();
		}
		
		DrawEventPopup();
	}
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

void ABaseHUD::DrawPopulationNum()
{
	if (BaseGameplayWidget && Player && Player->PlayerFaction)
	{
		BaseGameplayWidget->PopText->SetText(FText::AsNumber(Player->PlayerFaction->Population.Manpower));
	}
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

void ABaseHUD::GetActorsUnderSelectionBox()
{
	
}
