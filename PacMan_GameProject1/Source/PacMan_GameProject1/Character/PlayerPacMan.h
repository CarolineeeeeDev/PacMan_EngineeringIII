// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../PacMan_GameProject1Character.h"
#include "PlayerPacMan.generated.h"

UCLASS()
class PACMAN_GAMEPROJECT1_API APlayerPacMan : public APacMan_GameProject1Character
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerPacMan();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
