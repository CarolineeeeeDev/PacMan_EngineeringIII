#include "GhostAIController.h"
#include "GameFramework/Pawn.h"

AGhostAIController::AGhostAIController()
{

}

void AGhostAIController::BeginPlay()
{
	Super::BeginPlay();
	ControlledPawn = GetPawn();
}
