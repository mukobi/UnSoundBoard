// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundPlayer.h"
#include "MediaSoundComponent.h"
#include "MediaPlayer.h"

// Sets default values
ASoundPlayer::ASoundPlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Root"));

	MediaSoundComponent = CreateDefaultSubobject<UMediaSoundComponent>(TEXT("Media Sound"));
	MediaSoundComponent->SetupAttachment(SceneRoot);
}

// Called when the game starts or when spawned
void ASoundPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASoundPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ASoundPlayer::PlayMediaByPath(const FString& path)
{
	const FString fileAppendedPath = FString(TEXT("file://")) + path;

	UMediaPlayer* mediaPlayer = MediaSoundComponent->GetMediaPlayer();
	if (!mediaPlayer || !mediaPlayer->CanPlayUrl(fileAppendedPath))
	{
		const FString errorMessage = FString(TEXT("Can't play ")) + fileAppendedPath;
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, errorMessage);
		return false;
	}
	// else can play url
	mediaPlayer->OpenUrl(fileAppendedPath);
	return true;
}

