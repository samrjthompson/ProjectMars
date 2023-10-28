// Fill out your copyright notice in the Description page of Project Settings.


#include "ReadWriteJsonFile.h"

FString UReadWriteJsonFile::ReadStringFromFile(FString FilePath, bool& bOutSuccess, FString& OutInfoMessage)
{
	// Check if file exists
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read String from file failed - File doesn't exist - '%s'"), *FilePath);
		return "";
	}

	FString RetString = "";

	// Try to read the file, Output goes to RetString
	if (!FFileHelper::LoadFileToString(RetString, *FilePath))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read String from file failed - Unable to read file. Make sure it is a .txt file - '%s'"), *FilePath);
		return "";
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Read String from file succeeded - '%s'"), *FilePath);
	return RetString;
}

void UReadWriteJsonFile::WriteStringToFile(FString FilePath, FString String, bool& bOutSuccess, FString& OutInfoMessage)
{
	// Try to write string to file
	if (!FFileHelper::SaveStringToFile(String, *FilePath))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Write String to file failed - Was not able to write to file. Is the file read only? Is the path valid? - '%s'"), *FilePath);
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Write String to file succeeded - '%s'"), *FilePath);
}

TSharedPtr<FJsonObject> UReadWriteJsonFile::ReadJson(FString JsonFilePath, bool& bOutSuccess, FString& OutInfoMessage)
{
	FString JsonString = ReadStringFromFile(JsonFilePath, bOutSuccess, OutInfoMessage);
	if (!bOutSuccess)
	{
		return nullptr;
	}

	TSharedPtr<FJsonObject> RetJsonObject;

	// Try to convert string to json object. Output goes in RetJsonObject
	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(JsonString), RetJsonObject))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Read Json failed - Was not able to deserialize the json string. Is it the right format? - '%s'"), *JsonString);
		return nullptr;
	}

	bOutSuccess = true;
	OutInfoMessage = FString::Printf(TEXT("Read Json succeeded - '%s'"), *JsonFilePath);
	return RetJsonObject;
}

void UReadWriteJsonFile::WriteJson(FString JsonFilePath, TSharedPtr<FJsonObject> JsonObject, bool& bOutSuccess,
	FString& OutInfoMessage)
{
	FString JsonString;

	// Try to convert json object to string. Output goes to JsonString
	if (!FJsonSerializer::Serialize(JsonObject.ToSharedRef(), TJsonWriterFactory<>::Create(&JsonString, 0)))
	{
		bOutSuccess = false;
		OutInfoMessage = FString::Printf(TEXT("Write Json failed - Was not able to serialize the json string. Is it the JsonObject valid?"));
		return;
	}

	// Try to write json string to file
	WriteStringToFile(JsonFilePath, JsonString, bOutSuccess, OutInfoMessage);
	if (!bOutSuccess)
	{
		return;
	}

	bOutSuccess = true;
	OutInfoMessage = OutInfoMessage = FString::Printf(TEXT("Write Json succeeded - '%s'"), *JsonFilePath);
}
