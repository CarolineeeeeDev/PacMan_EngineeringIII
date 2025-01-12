// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWidget.h"
#include "../PacMan_PlayerState.h"

void UPlayerWidget::UpdatePowerText()
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        APlayerState* PlayerState = PlayerController->GetPlayerState<APlayerState>();
        if (PlayerState)
        {
            APacMan_PlayerState* PacManPlayerState = Cast<APacMan_PlayerState>(PlayerState);
            if (PacManPlayerState && PowerText)
            {
                PowerText->SetText(FText::FromString(FString::Printf(TEXT("%d"), PacManPlayerState->GetPower())));
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("PlayerState is not of type APacMan_PlayerState"));
            }
        }
    }
}