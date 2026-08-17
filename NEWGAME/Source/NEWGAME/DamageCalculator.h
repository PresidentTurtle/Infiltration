// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DamageCalculator.generated.h"


/**
 * 
 */
UCLASS()
class NEWGAME_API UDamageCalculator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Damage", meta = (WorldContext = "WorldContextObject"))
	static void DamageCalc(UObject* WorldContextObject,
		USceneComponent* ExplosionPoint,
		float& Damage,
		float ViewDistance,
		AActor*& DetectedActor,
		bool DebugShow,
		bool& Character
		);
	
};
