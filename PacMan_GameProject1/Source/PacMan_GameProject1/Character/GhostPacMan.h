#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "GhostPacMan.generated.h"

UCLASS()
class PACMAN_GAMEPROJECT1_API AGhostPacMan : public ACharacter
{
    GENERATED_BODY()

public:
    AGhostPacMan();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    void StartChase();
    void StopChase();

    void MoveAlongPath();
    void MoveToPlayer();

    void SwitchTargetPoint();

    UFUNCTION(BlueprintCallable)
    void AttackPlayer();

    UPROPERTY(EditAnywhere, Category = "Default")
    AActor* PatrolPoint1;

    UPROPERTY(EditAnywhere, Category = "Default")
    AActor* PatrolPoint2;

    AActor* CurrentTargetPoint;// PatrolPoint1 or PatrolPoint2 or PlayerPawn

private:
    FTimerHandle ChaseTimerHandle;
    bool bIsChasing;
    float ChaseDuration;
};
