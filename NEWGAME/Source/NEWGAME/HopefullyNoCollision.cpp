// Fill out your copyright notice in the Description page of Project Settings.


#include "HopefullyNoCollision.h"

UHopefullyNoCollision::UHopefullyNoCollision()
{
	
	PrimaryComponentTick.bCanEverTick = true;
}


void UHopefullyNoCollision::BeginPlay()
{
	Super::BeginPlay();
}

void UHopefullyNoCollision::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	bool physics = IsSimulatingPhysics();
	if (physics == true)
	{
		AActor* Owner = GetOwner();
		Owner -> SetActorEnableCollision(false);
		UE_LOG(LogTemp, Warning, TEXT("This Worked!"));
	}
}