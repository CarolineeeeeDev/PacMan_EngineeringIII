// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "PlayerWidget.generated.h"

UCLASS()
class PACMAN_GAMEPROJECT1_API UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UTextBlock* PowerText;

    UFUNCTION(BlueprintCallable)
    void UpdatePowerText();

};
