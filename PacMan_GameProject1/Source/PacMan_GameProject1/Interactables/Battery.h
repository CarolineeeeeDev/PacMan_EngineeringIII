#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Battery.generated.h"

UCLASS()
class PACMAN_GAMEPROJECT1_API ABattery : public AActor
{
	GENERATED_BODY()
	
public:
    ABattery();

protected:
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Default")
    class UCapsuleComponent* CollisionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    class UStaticMeshComponent* StaticMeshComponent;

    UFUNCTION(BlueprintCallable)
    void OverlapWithPlayer();

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    int32 PowerIncreaseAmount;
};
