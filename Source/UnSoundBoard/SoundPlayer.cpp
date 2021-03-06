// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundPlayer.h"
#include "MediaSoundComponent.h"
#include "MediaPlayer.h"

// Sets default values
ASoundPlayer::ASoundPlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

bool ASoundPlayer::PlayMediaByPathAndPlayer(const FString& fileAppendedPath, UMediaPlayer* mediaPlayer)
{
    if (!mediaPlayer || !mediaPlayer->CanPlayUrl(fileAppendedPath))
	{
		const FString errorMessage = FString(TEXT("Can't play ")) + fileAppendedPath;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, errorMessage);
		return false;
	}
    // else can play url
	mediaPlayer->OpenUrl(fileAppendedPath);
	GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, fileAppendedPath);
	OnFilePlayed.Broadcast(fileAppendedPath);
	return true;
}

bool ASoundPlayer::PlayMediaByPath(const FString& path)
{
	const FString fileAppendedPath = FString(TEXT("file://")) + path;

	UMediaPlayer* mediaPlayer = MediaPlayers[CurrentMediaPlayerIndex];
	if (bAllowSimultaneousSounds)
	{
		CurrentMediaPlayerIndex += 1;
		CurrentMediaPlayerIndex %= MediaPlayers.Num();
	}

	return PlayMediaByPathAndPlayer(fileAppendedPath, mediaPlayer);
}

void ASoundPlayer::StopAllSounds()
{
	for (UMediaPlayer* mediaPlayer : MediaPlayers)
	{
		mediaPlayer->Close();
	}
}

