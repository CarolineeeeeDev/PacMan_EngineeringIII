#pragma once

#include "CoreMinimal.h"
#include "Battery.h"
#include "AIController.h"
#include "Battery_Chase.generated.h"

UCLASS()
class PACMAN_GAMEPROJECT1_API ABattery_Chase : public ABattery
{
	GENERATED_BODY()

public:
    ABattery_Chase();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
    float ChaseDuration;

    UPROPERTY()
    bool bIsChasing;


    UFUNCTION(BlueprintCallable)
    void ActivateChaseEffect();

    void RestoreAIBehavior();

protected:
    UPROPERTY()
    class AAIController* OriginalAIController;

    FTimerHandle TimerHandle_RestoreBehavior;
	
};
