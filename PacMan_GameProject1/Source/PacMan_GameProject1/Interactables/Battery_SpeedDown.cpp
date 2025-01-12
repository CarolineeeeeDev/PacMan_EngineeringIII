#include "Battery_SpeedDown.h"
#include "../Character/PlayerPacMan.h"
#include "GameFramework/CharacterMovementComponent.h"


ABattery_SpeedDown::ABattery_SpeedDown()
{
	SpeedDownDuration = 5.0f;
}

void ABattery_SpeedDown::SlowPlayer()
{
	APlayerPacMan* PlayerCharacter = Cast<APlayerPacMan>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerCharacter)
	{
		float CurrentSpeed = PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed;
		PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed = CurrentSpeed * 0.5f;
		GetWorld()->GetTimerManager().SetTimer(SpeedDownTimerHandle, this, &ABattery_SpeedDown::RecoverSpeed, SpeedDownDuration, false);
	}
}

void ABattery_SpeedDown::RecoverSpeed()
{
	APlayerPacMan* PlayerCharacter = Cast<APlayerPacMan>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerCharacter)
	{
		PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed *= 2.0f;
	}
}
