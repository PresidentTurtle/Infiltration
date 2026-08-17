// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "HopefullyNoCollision.generated.h"

/**
 * 
 */
UCLASS()
class NEWGAME_API UHopefullyNoCollision : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:
	UHopefullyNoCollision();
	
protected:
	virtual void BeginPlay() override;
	
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
