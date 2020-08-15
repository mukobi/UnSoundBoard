// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundPlayer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFilePlayedDelegate, FString, filepath);

UCLASS()
class UNSOUNDBOARD_API ASoundPlayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASoundPlayer();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<class UMediaPlayer*> MediaPlayers;

    UPROPERTY()
    uint32 CurrentMediaPlayerIndex = 0;

	UPROPERTY(BlueprintAssignable, Category = "SoundPlayer")
	FFilePlayedDelegate OnFilePlayed;

protected:
	bool PlayMediaByPathAndPlayer(const FString& path, class UMediaPlayer* mediaPlayer);


public:	
	UFUNCTION(BlueprintCallable)
	bool PlayMediaByPath(const FString& path);

	UFUNCTION(BlueprintCallable)
	void StopAllSounds();
};
