// Fill out your copyright notice in the Description page of Project Settings.
#include "CoreFunctions.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"
#include "Containers/UnrealString.h"

int UCoreFunctions::Suma(int numar1, int numar2)
{
	return numar1+numar2;
}

int UCoreFunctions::Scadere(int numar1, int numar2)
{
	return numar1-numar2;
	
}

int UCoreFunctions::IfNeg(int numar)
{
	if (numar < 0)
		return 1;
	return 0;
}

int UCoreFunctions::IfZero(int numar)
{
	if (numar == 0)
		return 1;
	return 0;
}

int UCoreFunctions::Increment(int numar)
{
	return ++numar;
}

int UCoreFunctions::Decrement(int numar)
{
	return --numar;
}

FString UCoreFunctions::LoadFileToString(FString Filename)
{
	UE_LOG(LogTemp, Warning, TEXT("Received Filename from Blueprint. Filename was: %s"), *Filename);

	FString directory = FPaths::ProjectContentDir();
	UE_LOG(LogTemp, Warning, TEXT("ContentDirectory: %s"), *directory);

	FString myFilePath = directory / Filename;
	UE_LOG(LogTemp, Warning, TEXT("MyFilePath: %s"), *myFilePath);

	FString result;
	if (FPaths::FileExists(myFilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("Found the file."));
		if (FFileHelper::LoadFileToString(result, *myFilePath))
		{
			UE_LOG(LogTemp, Warning, TEXT("Successfully loaded the file. Content was: %s"), *result);
			return result;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("An error occured while attempting to load the file."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to find file in specified directory."));
	}
	return FString("We have an error!");
}

TArray<FString> UCoreFunctions::LoadFileToStringArray(FString filename)
{
	FString directory = FPaths::ProjectContentDir();
	TArray<FString> result;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory)) {
		FString myFile = directory + "/" + filename;
		FFileHelper::LoadFileToStringArray(result, *myFile);
	}
	return result;
}

FString UCoreFunctions::GetInputLine(FString sourceString, int linie)
{
	FString Str = sourceString;
	TArray<FString> Parsed;
	Str.ParseIntoArray(Parsed, TEXT("\n"), true);
	return Parsed[linie];
}
TMap<int32, FString> MapString;

void UCoreFunctions::FileInfoSeparation(FString FileContent)
{
	
	FString Str = LoadFileToString(FileContent);
	TArray<FString> Parsed;
	Str.ParseIntoArray(Parsed, TEXT(" "), true);
	for(int i=0;i<Parsed.Num();i++)
	{
		MapString.Add(i, Parsed[i]);
		
	}

}
