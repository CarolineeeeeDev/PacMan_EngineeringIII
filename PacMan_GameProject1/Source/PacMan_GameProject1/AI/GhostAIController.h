// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GhostAIController.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_GAMEPROJECT1_API AGhostAIController : public AAIController
{
	GENERATED_BODY()
public:
    AGhostAIController();

protected:
    virtual void BeginPlay() override;

private:
    APawn* ControlledPawn;
	
};
