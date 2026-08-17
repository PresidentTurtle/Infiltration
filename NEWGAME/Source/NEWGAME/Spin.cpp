// Fill out your copyright notice in the Description page of Project Settings.


#include "Spin.h"

// Sets default values for this component's properties
USpin::USpin()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpin::BeginPlay()
{
	Super::BeginPlay();
	MyOwner = GetOwner();
	if (IsValid(MyOwner))
	{
		OriginalRotation = MyOwner->GetActorRotation();
	}
	
	
	
}


// Called every frame
void USpin::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!IsValid(MyOwner)) return;
	
		FVector NewLocation = MyOwner->GetActorLocation();
		FRotator NewRotation = MyOwner->GetActorRotation();
		if (NewRotation.Yaw < OriginalRotation.Yaw + MaxRight && Right == true)
		{
			float DeltaRoation = DeltaTime * 10.0f;
			NewRotation.Yaw += DeltaRoation;
			MyOwner->SetActorLocationAndRotation(NewLocation, NewRotation);
			
			if (NewRotation.Yaw >= OriginalRotation.Yaw + MaxRight && Right == true)
			{
				Right = false;
			}
			
		}
		if (NewRotation.Yaw > OriginalRotation.Yaw - MaxLeft && Right == false)
		{
			float DeltaRoation = DeltaTime * 10.0f;
			NewRotation.Yaw -= DeltaRoation;
			MyOwner->SetActorLocationAndRotation(NewLocation, NewRotation);
			if (NewRotation.Yaw <= OriginalRotation.Yaw - MaxLeft && Right == false)
			{
				Right = true;
			}
		}
}

