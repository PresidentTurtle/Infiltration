// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsChecker.h"

#include "Kismet/GameplayStatics.h"
#include "Slate/SGameLayerManager.h"

bool UPhysicsChecker::LineTrace(UObject* WorldContextObject,
                                USceneComponent* FirePoint,
                                float ViewDistance,
                                float ViewAngle,
                                AActor*& DetectedActor,
                                FRotator& ActorRotate,
                                bool DebugShow)
	
{
	if (!WorldContextObject || !FirePoint) return false;
	
	UWorld* World = WorldContextObject->GetWorld();
	if (!World) return false;
	
	FVector Forward = FirePoint->GetForwardVector();
	FVector Start = FirePoint->GetComponentLocation();
	
	
	FVector Start2 = FirePoint->GetComponentLocation() - FVector(0, 0, 200);
	
	TArray<FOverlapResult> Overlaps;
	
	         FCollisionShape Sphere = FCollisionShape::MakeSphere(ViewDistance);
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(FirePoint->GetOwner());
	
	bool bAny = World->OverlapMultiByChannel(
		Overlaps,
		Start,
		FQuat::Identity,
		ECC_Pawn,
		Sphere,
		Params);
	
	float BestDot = -1.f;
	DetectedActor = nullptr;
	
	float CosAngle = FMath::Cos(FMath::DegreesToRadians(ViewAngle));
	
	for (auto& O : Overlaps)
	{
		AActor* Actor = O.GetActor();
		if (!Actor) continue;
		
		FVector ToTarget = (Actor->GetActorLocation() - Start).GetSafeNormal();
		float Dot = FVector::DotProduct(Forward, ToTarget);
		
		if (Dot > CosAngle)
		{
			ACharacter* Player = Cast<ACharacter>(Actor);
			FHitResult Hit;
			bool bHit = World->LineTraceSingleByChannel(Hit, Start, Actor->GetActorLocation(), ECC_GameTraceChannel1, Params);
			if (Hit.GetActor() == Player)
			{
				
				if (Player && IsValid(Player))
				{
					DetectedActor = Player;
					ActorRotate = Player->GetActorRotation();
				}
			}
		}
		if (DebugShow == true)
		{
			DrawDebugLine(World, Start, Actor-> GetActorLocation(), FColor::Yellow, false, 0.1f);
		}
	}
	FVector LeftEdge = FRotator(0, -ViewAngle, 0).RotateVector(Forward);
	FVector RightEdge = FRotator(0, ViewAngle, 0).RotateVector(Forward);
	if (DebugShow == true)
	{
		DrawDebugLine(World, Start, Start + LeftEdge * ViewDistance, FColor::Red, false, 0.1f);
		DrawDebugLine(World, Start, Start + RightEdge * ViewDistance, FColor::Red, false, 0.1f);
		DrawDebugLine(World, Start, Start + Forward * ViewDistance, FColor::Blue, false, 0.1f);
		DrawDebugSphere(
		World,
		Start,
		ViewDistance,
		24,
		FColor::Blue,
		false,
		0.1f,   // short lifetime (refresh every tick)
		0,
		2.0f
	);
		DrawDebugCone(
		World,
		Start,                          // camera position
		Forward,                        // forward direction
		ViewDistance,                   // length of vision
		FMath::Cos(FMath::DegreesToRadians(ViewAngle)), // inner cone
		FMath::Cos(FMath::DegreesToRadians(ViewAngle)), // outer cone
		12,                             // segments
		FColor::Green,
		false,
		0.1f,
		0,
		2.0f
	);
	}
	return DetectedActor != nullptr;
}

void UPhysicsChecker::LookAtPlayerNPC(UObject* WorldContextObject, AActor* Actor, AActor* SecActor, float InterpSpeed)
{
	if (!IsValid(Actor)) return;
	if (!IsValid(SecActor)) return;
	FVector Location = SecActor->GetActorLocation();
	FVector Start = Actor->GetActorLocation();
	FRotator LookAtRotate = (Location - Start).Rotation();
	LookAtRotate.Pitch = 0.0f;
	LookAtRotate.Roll = 0.0f;
	FRotator Current = Actor->GetActorRotation();
	LookAtRotate = FMath::RInterpTo(Current, LookAtRotate, WorldContextObject->GetWorld()->GetDeltaSeconds(), InterpSpeed);
	
	Actor->SetActorRotation(LookAtRotate);
}
