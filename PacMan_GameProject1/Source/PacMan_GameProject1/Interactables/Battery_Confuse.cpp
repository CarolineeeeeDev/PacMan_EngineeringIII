#include "Battery_Confuse.h"

ABattery_Confuse::ABattery_Confuse()
{
	ConfuseDuration = 5.0f;
	ConfuseUIWidget = nullptr;
}

void ABattery_Confuse::ConfusePlayer()
{
	if (ConfuseUIClass)
	{
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

		if (PlayerController)
		{
			ConfuseUIWidget = CreateWidget<UUserWidget>(PlayerController, ConfuseUIClass);

			if (ConfuseUIWidget)
			{
				ConfuseUIWidget->AddToViewport();
				GetWorld()->GetTimerManager().SetTimer(RemoveUITimerHandle, this, &ABattery_Confuse::RemoveConfuseUI, ConfuseDuration, false);
			}
		}
	}
}

void ABattery_Confuse::RemoveConfuseUI()
{
	if (ConfuseUIWidget)
	{
		ConfuseUIWidget->RemoveFromViewport();
		ConfuseUIWidget = nullptr;
	}
}
