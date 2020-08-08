// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityLibrary.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"

void UUtilityLibrary::GetFilesInFolder(TArray<FString>& out, FString SearchPath)
{
    UE_LOG(LogTemp, Warning, TEXT("SearchPath %s"), *SearchPath);
    FPaths::NormalizeDirectoryName(SearchPath);
    UE_LOG(LogTemp, Warning, TEXT("SearchPath %s"), *SearchPath);
    IFileManager& FileManager = IFileManager::Get();
}
