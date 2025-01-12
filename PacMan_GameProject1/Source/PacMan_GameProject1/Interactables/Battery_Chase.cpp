// Fill out your copyright notice in the Description page of Project Settings.


#include "Battery_Chase.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "NavigationSystem.h"
#include "Kismet/GameplayStatics.h"
#include "../Character/GhostPacMan.h"

ABattery_Chase::ABattery_Chase()
{
    ChaseDuration = 5.0f;
    bIsChasing = false;
    OriginalAIController = nullptr;
}

void ABattery_Chase::ActivateChaseEffect()
{

    TArray<AActor*> Ghosts;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGhostPacMan::StaticClass(), Ghosts);

    for (AActor* GhostActor : Ghosts)
    {
        AGhostPacMan* Ghost = Cast<AGhostPacMan>(GhostActor);
        if (Ghost)
        {
            Ghost->StartChase();
        }
    }
}

void ABattery_Chase::RestoreAIBehavior()
{
    UE_LOG(LogTemp, Log, TEXT("Stop"));

}
