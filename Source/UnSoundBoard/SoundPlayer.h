// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundPlayer.generated.h"

UCLASS()
class UNSOUNDBOARD_API ASoundPlayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASoundPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UMediaPlayer*> MediaPlayers;

	bool PlayMediaByPathAndPlayer(const FString& path, class UMediaPlayer* mediaPlayer);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	bool PlayMediaByPath(const FString& path);
};
