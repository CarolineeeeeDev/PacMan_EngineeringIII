#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PacMan_GameProject1GameMode.generated.h"

UCLASS(minimalapi)
class APacMan_GameProject1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APacMan_GameProject1GameMode();

	FTimerHandle PowerDecrementTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	int32 PowerDecrementRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	int32 RemainingBatteries;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	TSubclassOf<class UUserWidget> GameOverUIClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	TSubclassOf<class UUserWidget> WinGameUIClass;

	UPROPERTY()
	class UUserWidget* GameOverWidget;
	UPROPERTY()
	class UUserWidget* WinGameWidget;

	UFUNCTION()
	void DecreasePower(); //Power decreases as time passes

	virtual void BeginPlay() override;

	void EndGame();
	void WinGame();
};



