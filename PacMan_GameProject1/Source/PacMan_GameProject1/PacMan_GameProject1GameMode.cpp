// Copyright Epic Games, Inc. All Rights Reserved.

#include "PacMan_GameProject1GameMode.h"
#include "PacMan_GameProject1Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "PacMan_PlayerState.h"

APacMan_GameProject1GameMode::APacMan_GameProject1GameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/PacMan/Blueprints/BP_PlayerPacMan"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PlayerStateClass = APacMan_PlayerState::StaticClass();
	PowerDecrementRate = 1;
}

void APacMan_GameProject1GameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(PowerDecrementTimerHandle, this, &APacMan_GameProject1GameMode::DecreasePower, 1.0f, true);

	if (GameOverUIClass)
	{
		GameOverWidget = CreateWidget<UUserWidget>(GetWorld(), GameOverUIClass);
	}
}

void APacMan_GameProject1GameMode::DecreasePower()
{
	APacMan_PlayerState* PlayerState = GetWorld()->GetFirstPlayerController()->GetPlayerState<APacMan_PlayerState>();

	if (PlayerState)
	{
		if (PlayerState->GetPower() > 0)
		{
			PlayerState->DecreasePower(PowerDecrementRate);
		}
		else
		{
			EndGame();
		}
	}
}

void APacMan_GameProject1GameMode::EndGame()
{
	GetWorld()->GetTimerManager().ClearTimer(PowerDecrementTimerHandle);

	if (GameOverWidget)
	{
		GameOverWidget->AddToViewport();
	}
}