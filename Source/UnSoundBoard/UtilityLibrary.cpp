// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityLibrary.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"

void UUtilityLibrary::GetFilesInFolder(TArray<FString>& out, FString SearchPath, bool bFindFiles, bool bFindDirectories)
{
    FPaths::NormalizeDirectoryName(SearchPath);
    SearchPath = SearchPath + "/*"; // necessary to find folder contents
    //UE_LOG(LogTemp, Warning, TEXT("Finding files in: %s"), *SearchPath);
    IFileManager& FileManager = IFileManager::Get();
    FileManager.FindFiles(out, *SearchPath, bFindFiles, bFindDirectories);
    out.Sort();
}

FString UUtilityLibrary::GetRandomFileInSubfolder(FString RootDir, FString Subdirname)
{
    FPaths::NormalizeDirectoryName(RootDir);
    FPaths::NormalizeDirectoryName(Subdirname);
    FString fullSubdirectoryPath = RootDir + "/" + Subdirname;
    FString fullSearchpath = fullSubdirectoryPath + "/*";
    //UE_LOG(LogTemp, Warning, TEXT("Finding files in: %s"), *fullSearchpath);

    IFileManager& FileManager = IFileManager::Get();
    TArray<FString> foundFiles;
    FileManager.FindFiles(foundFiles, *fullSearchpath, true, false);

    if (foundFiles.Num() == 0)
    {
        return "";
    }
    
    int randomIndex = FMath::RandRange(0, foundFiles.Num() - 1);
    return fullSubdirectoryPath + "/" + foundFiles[randomIndex];
}

