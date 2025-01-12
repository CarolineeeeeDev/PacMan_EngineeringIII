#include "GhostPacMan.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "../PacMan_PlayerState.h"

AGhostPacMan::AGhostPacMan()
{
    PrimaryActorTick.bCanEverTick = true;
    ChaseDuration = 5.0f;
    bIsChasing = false; 
}

void AGhostPacMan::StartChase()
{
    UE_LOG(LogTemp, Warning, TEXT("Ghost is chasing the player!"));
    GetWorld()->GetTimerManager().SetTimer(ChaseTimerHandle, this, &AGhostPacMan::StopChase, ChaseDuration, false); 
    bIsChasing = true;
}

void AGhostPacMan::StopChase()
{
    UE_LOG(LogTemp, Warning, TEXT("Ghost stopped chasing."));
    bIsChasing = false;
}

void AGhostPacMan::BeginPlay()
{
    Super::BeginPlay();

    if (PatrolPoint1)
    {
        CurrentTargetPoint = PatrolPoint1;
    }
}

void AGhostPacMan::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!bIsChasing)
    {
        MoveAlongPath();
    }
    else
    {
        MoveToPlayer();
    }
}

void AGhostPacMan::MoveAlongPath()
{
    AAIController* AIController = Cast<AAIController>(GetController());
    if (AIController && CurrentTargetPoint)
    {
        FVector GhostLocation = GetActorLocation();
        FVector TargetLocation = CurrentTargetPoint->GetActorLocation();

        float Distance = FVector::Dist(GhostLocation, TargetLocation); 

        if (Distance <= 100.0f)
        {
            SwitchTargetPoint();
        }
        else
        {
            AIController->MoveToActor(CurrentTargetPoint);

        }
    }
    if (bIsChasing) MoveToPlayer();
}

void AGhostPacMan::MoveToPlayer()
{
    AAIController* AIController = Cast<AAIController>(GetController());
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    if (AIController && PlayerPawn)
    {
        UE_LOG(LogTemp, Warning, TEXT("Ghost is moving towards player!"));

        AIController->MoveToActor(PlayerPawn);
    }

}

void AGhostPacMan::SwitchTargetPoint()
{
    if (CurrentTargetPoint == PatrolPoint1)
    {
        CurrentTargetPoint = PatrolPoint2;
    }
    else
    {
        CurrentTargetPoint = PatrolPoint1;
    }
}

void AGhostPacMan::AttackPlayer()
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        APlayerState* PlayerStatePtr = PlayerController->GetPlayerState<APlayerState>();
        if (PlayerStatePtr)
        {
            APacMan_PlayerState* PacManPlayerState = Cast<APacMan_PlayerState>(PlayerStatePtr);
            if (PacManPlayerState)
            {
                PacManPlayerState->DecreasePower(20);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("PlayerState is not of type APacMan_PlayerState"));
            }
        }
    }
}
