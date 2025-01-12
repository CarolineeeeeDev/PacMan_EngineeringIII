// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PacMan_GameProject1GameMode.generated.h"

UCLASS(minimalapi)
class APacMan_GameProject1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APacMan_GameProject1GameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	int32 PowerDecrementRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UUserWidget> GameOverUIClass;

	UPROPERTY()
	class UUserWidget* GameOverWidget;

	FTimerHandle PowerDecrementTimerHandle;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void EndGame();

	UFUNCTION()
	void DecreasePower();
};



