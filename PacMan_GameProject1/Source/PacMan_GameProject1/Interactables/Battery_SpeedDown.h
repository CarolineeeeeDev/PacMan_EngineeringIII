// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Battery.h"
#include "Battery_SpeedDown.generated.h"

UCLASS()
class PACMAN_GAMEPROJECT1_API ABattery_SpeedDown : public ABattery
{
	GENERATED_BODY()
	
public:
	ABattery_SpeedDown();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	float SpeedDownDuration;

	FTimerHandle SpeedDownTimerHandle;

	UFUNCTION(BlueprintCallable)
	void SlowPlayer();

	void RecoverSpeed();

};
