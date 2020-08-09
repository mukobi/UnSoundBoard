// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilityLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UNSOUNDBOARD_API UUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "UnSoundBoardUtil")
	static void GetFilesInFolder(TArray<FString>& out, FString SearchPath, bool bFindFiles=true, bool bFindDirectories=true);
	
    
    UFUNCTION(BlueprintPure, Category = "UnSoundBoardUtil")
	static FString GetRandomFileInSubfolder(FString RootDir, FString Subdirname);
};
