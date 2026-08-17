// Fill out your copyright notice in the Description page of Project Settings.


#include "KeySpin.h"

// Sets default values for this component's properties
UKeySpin::UKeySpin()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UKeySpin::BeginPlay()
{
	Super::BeginPlay();
	MyOwner = GetOwner();
	
}


// Called every frame
void UKeySpin::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	
	RunningTime += DeltaTime;
	float DeltaHeight = FMath::Sin(RunningTime * HeightSpeed) * 20.0f  * DeltaTime;
	MyOwner->AddActorWorldOffset(FVector(0.0f, 0.0f, DeltaHeight));
	
	FRotator DeltaRotation = FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f);
	MyOwner->AddActorLocalRotation(DeltaRotation);

	
}

