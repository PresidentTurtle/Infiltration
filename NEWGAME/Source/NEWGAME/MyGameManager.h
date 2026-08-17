// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ObjectMacros.h"
#include "MyGameManager.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8
{
	MainMenu UMETA(DisplayName = "Main Menu"),
	Playing UMETA(DisplayName = "Playing"),
	Paused UMETA(DisplayName = "Paused"),
	GameOver UMETA(DisplayName = "Game Over"),
};

USTRUCT(BlueprintType)
struct FGameStateData
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State Data")
	EGameState CurrentState = EGameState::MainMenu;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State Data")
	EGameState PreviousState = EGameState::MainMenu;
};

UCLASS()
class NEWGAME_API UMyGameManager : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	//Will Create and give options to set the Game Level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
	int32 level = 0;
	UFUNCTION(BlueprintCallable, Category = "Game Data")
	void SetGameLevel(int32 NewGameLevel);
	//Will Create and give options to set the sensitivity
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
	float sensitivity = 1;
	UFUNCTION(BlueprintCallable, Category = "Game Data")
	void SetSensitivity(float NewSensitivity);
	//Will Create and give options to set whether the Player is using a controller or K&M
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
	bool bIsGamePad;
	UFUNCTION(BlueprintCallable, Category = "Game Data")
	void SetGamePad(bool newBool);
	//Creates  and gives the options to switch and change Game States
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State Management")
	FGameStateData GameStateData;
	UFUNCTION(BlueprintCallable, Category = "Game State Management")
	void SetGameState(EGameState NewState);
	
};
