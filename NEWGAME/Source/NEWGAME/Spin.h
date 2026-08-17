// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Spin.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NEWGAME_API USpin : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpin();
	AActor* MyOwner;
	FRotator OriginalRotation;
	bool Right = true;
	UPROPERTY(EditAnywhere)
	float MaxRight = 90;
	UPROPERTY(EditAnywhere)
	float MaxLeft = 90;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


		
};
