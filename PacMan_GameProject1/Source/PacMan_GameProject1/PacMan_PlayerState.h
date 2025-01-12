// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PacMan_PlayerState.generated.h"

UCLASS()
class PACMAN_GAMEPROJECT1_API APacMan_PlayerState : public APlayerState
{
	GENERATED_BODY()

    APacMan_PlayerState();

    UPROPERTY(VisibleAnywhere, Category = "Default")
    int32 Power;

public:
    void IncreasePower(int32 Amount);
    void DecreasePower(int32 Amount);

    int32 GetPower();

};
