// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityLibrary.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"

void UUtilityLibrary::GetFilesInFolder(TArray<FString>& out, FString SearchPath, bool bFindFiles, bool bFindDirectories)
{
    FPaths::NormalizeDirectoryName(SearchPath);
    SearchPath = SearchPath + "/*"; // necessary to find folder contents
    IFileManager& FileManager = IFileManager::Get();
    FileManager.FindFiles(out, *SearchPath, bFindFiles, bFindDirectories);
    out.Sort();
}


FString UUtilityLibrary::GetRandomFileInSubfolder(FString RootDir, FString Subdirname)
{
	static int32 LastChosenFileIndex = -1; // changes with each call
    static const uint32 NumTriesBeforePickingSameIndex = 8;

    FPaths::NormalizeDirectoryName(RootDir);
    FPaths::NormalizeDirectoryName(Subdirname);
    FString fullSubdirectoryPath = RootDir + "/" + Subdirname;
    FString fullSearchpath = fullSubdirectoryPath + "/*";

    IFileManager& FileManager = IFileManager::Get();
    TArray<FString> foundFiles;
    FileManager.FindFiles(foundFiles, *fullSearchpath, true, false);

    if (foundFiles.Num() == 0)
    {
        return "";
    }

    int32 randomIndex = -1;
    for (uint32 i = 0; i < NumTriesBeforePickingSameIndex; i++)
    {
        randomIndex = FMath::RandRange(0, foundFiles.Num() - 1);
        if (randomIndex != LastChosenFileIndex)
        {
            break;
        }

    }
    LastChosenFileIndex = randomIndex;

    return fullSubdirectoryPath + "/" + foundFiles[randomIndex];
}

