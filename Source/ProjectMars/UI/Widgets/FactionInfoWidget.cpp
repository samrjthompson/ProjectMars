// Fill out your copyright notice in the Description page of Project Settings.


#include "FactionInfoWidget.h"

#include "Components/TextBlock.h"
#include "ProjectMars/Utils/ReadWriteJsonFile.h"

UFactionInfoWidget::UFactionInfoWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFactionInfoWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PopulateFactionInfoMap();
}

void UFactionInfoWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UFactionInfoWidget::SetFactionInfo(const FString& Name)
{
	const FString Text = *FactionInfoMap.Find(Name);
	FactionInfoText->SetText(FText::FromString(Text));
}

void UFactionInfoWidget::PopulateFactionInfoMap()
{
	bool bSuccess;
	FString Output;
	const FString GameContentDirectory = FPaths::GameSourceDir();
	const FString JsonPath = GameContentDirectory + "ProjectMars/TempJson/Nations/FactionInfo.json";
	const TSharedPtr<FJsonObject> Json = UReadWriteJsonFile::ReadJson(JsonPath, bSuccess, Output);

	for (const auto& Elem : Json->Values)
	{
		const auto Key = Elem.Key;
		FactionInfoMap.Add(Key, Json->GetStringField(Key));
	}
	
	/*const FString RomeText;
	FactionInfoMap.Add("FactionButton_Rome", RomeText);
	
	const FString CarthageText;
	FactionInfoMap.Add("FactionButton_Carthage", CarthageText);

	const FString SamniumText;
	FactionInfoMap.Add("FactionButton_Samnium", SamniumText);*/
}
