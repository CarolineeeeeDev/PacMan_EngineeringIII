// Fill out your copyright notice in the Description page of Project Settings.


#include "Battery.h"
#include "../PacMan_PlayerState.h"
#include "../PacMan_GameProject1GameMode.h"

#include "Kismet/GameplayStatics.h"


// Sets default values
ABattery::ABattery()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    RootComponent = StaticMeshComponent;

    CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
    CollisionComponent->SetupAttachment(RootComponent);

    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    CollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

    PowerIncreaseAmount = 5;
}

void ABattery::OverlapWithPlayer()
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        APlayerState* PlayerState = PlayerController->GetPlayerState<APlayerState>();
        if (PlayerState)
        {
            APacMan_PlayerState* PacManPlayerState = Cast<APacMan_PlayerState>(PlayerState);
            APacMan_GameProject1GameMode* GameMode = Cast<APacMan_GameProject1GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
            if (PacManPlayerState)
            {
                PacManPlayerState->IncreasePower(PowerIncreaseAmount);
                GameMode->RemainingBatteries -= 1;
                if (GameMode->RemainingBatteries <= 0) GameMode->WinGame();
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("PlayerState is not of type APacMan_PlayerState"));
            }
        }
    }
}