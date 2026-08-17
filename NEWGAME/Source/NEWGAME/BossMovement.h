// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BossMovement.generated.h"

/**
 * 
 */
UCLASS()
class NEWGAME_API UBossMovement : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

public:

UFUNCTION(BlueprintCallable, Category = "BossMovement", meta = (WorldContext = "WorldContextObject"))
static void BossFight(
						UObject* WorldContextObject,
						AActor* Actor,
						bool Move,
						float Time
						);
	
	UFUNCTION(BlueprintCallable, Category = "BossMovement", meta = (WorldContext = "WorldContextObject"))
	static void LookAtPlayer(
							UObject* WorldContextObject,
							AActor* Actor,
							AActor* SecActor
							);
	
	UFUNCTION(BlueprintCallable, Category = "BossMovement", meta = (WorldContext = "WorldContextObject"))
	static void LookAtPlayerAmmo(UObject* WorldContextObject, AActor* Actor, FVector Location);
};


