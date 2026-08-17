// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameManager.h"

void UMyGameManager::Init()
{
	Super::Init();
	level = 0;
	sensitivity = 1;
	
}

void UMyGameManager::SetGameLevel(int32 NewGameLevel)
{
	level = NewGameLevel;
}

void UMyGameManager::SetSensitivity(float NewSensitivity)
{
	sensitivity = NewSensitivity;
}

void UMyGameManager::SetGamePad(bool newBool)
{
	bIsGamePad = newBool;
}

void UMyGameManager::SetGameState(EGameState NewState)
{
	if (GameStateData.CurrentState == NewState)
	{
		return;
	}
	GameStateData.PreviousState = GameStateData.CurrentState;
	GameStateData.CurrentState = NewState;
	
	switch (NewState)
	{
	case EGameState::MainMenu:
		break;
	case EGameState::Playing:
		break;
	case EGameState::Paused:
		break;
	case EGameState::GameOver:
		break;
		
	default:
		break;
	}
}
