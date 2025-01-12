// Fill out your copyright notice in the Description page of Project Settings.


#include "PacMan_PlayerState.h"

APacMan_PlayerState::APacMan_PlayerState()
{
	Power = 100;
}

void APacMan_PlayerState::IncreasePower(int32 Amount)
{
	Power = FMath::Clamp(Power + Amount, 0, 100);
}

void APacMan_PlayerState::DecreasePower(int32 Amount)
{
	Power -= Amount;
	if (Power <= 0)
	{
		//EndGame
	}
}

int32 APacMan_PlayerState::GetPower()
{
	return Power;
}
