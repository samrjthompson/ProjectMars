// Fill out your copyright notice in the Description page of Project Settings.


#include "FNationsData.h"

#include "Logging/StructuredLog.h"
#include "ProjectMars/Utils/ReadWriteJsonFile.h"

FNationsData::FNationsData()
{
	FString Output;
	bool bSuccess;
	const FString GameContentDirPath = FPaths::ProjectContentDir();
	const FString SeasonsJsonPath = FString::Printf(TEXT("%sTempJson/Nations/Nations.json"), *GameContentDirPath);
	UE_LOGFMT(LogTemp, Error, "JSON PATH: {0}", SeasonsJsonPath);
	TSharedPtr<FJsonObject> SeasonsJson = UReadWriteJsonFile::ReadJson(SeasonsJsonPath, bSuccess, Output);

	for (const auto& Elem : SeasonsJson->Values)
	{
		const FString& Field = Elem.Key;
		UE_LOGFMT(LogTemp, Error, "KEY: {0}", Field);
	}

	UE_LOGFMT(LogTemp, Error, "JSON: {0}", Output);
}
