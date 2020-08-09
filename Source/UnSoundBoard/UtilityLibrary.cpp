// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityLibrary.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"

void UUtilityLibrary::GetFilesInFolder(TArray<FString>& out, FString SearchPath, bool bFindFiles, bool bFindDirectories)
{
    FPaths::NormalizeDirectoryName(SearchPath);
    SearchPath = SearchPath + "/*"; // necessary to find folder contents
    UE_LOG(LogTemp, Warning, TEXT("Finding files in: %s"), *SearchPath);
    IFileManager& FileManager = IFileManager::Get();
    FileManager.FindFiles(out, *SearchPath, bFindFiles, bFindDirectories);
    out.Sort();
}
