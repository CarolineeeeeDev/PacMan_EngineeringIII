#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Battery.h"
#include "Battery_Confuse.generated.h"

UCLASS()
class PACMAN_GAMEPROJECT1_API ABattery_Confuse : public ABattery
{
	GENERATED_BODY()

public:
	ABattery_Confuse();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	float ConfuseDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	TSubclassOf<class UUserWidget> ConfuseUIClass;

	UPROPERTY()
	UUserWidget* ConfuseUIWidget;

	FTimerHandle RemoveUITimerHandle;

	UFUNCTION(BlueprintCallable)
	void ConfusePlayer();

	void RemoveConfuseUI();
};
