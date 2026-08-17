// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageCalculator.h"

#include "Engine/OverlapResult.h"
#include "Kismet/GameplayStatics.h"

void UDamageCalculator::DamageCalc(UObject* WorldContextObject,
                                   USceneComponent* ExplosionPoint,
                                   float& Damage,
                                   float ViewDistance,
                                   AActor*& DetectedActor,
                                   bool DebugShow,
                                   bool& Character
                                   )
{
	UWorld* World = WorldContextObject->GetWorld();
	if (!IsValid(World)) return;
	if (!IsValid(ExplosionPoint)) return;
	FVector Start = ExplosionPoint->GetComponentLocation();
	
	TArray<FOverlapResult> Overlaps;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(ViewDistance);
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(ExplosionPoint->GetOwner());
	
	bool bAny = World->OverlapMultiByChannel(
		Overlaps,
		Start,
		FQuat::Identity,
		ECC_Pawn,
		Sphere,
		Params);
	
	DetectedActor = nullptr;
	
	for (auto& O : Overlaps)
	{
		AActor* Actor = O.GetActor();
		if (!Actor) return;
		FVector Target = (Actor->GetActorLocation() - Start).GetSafeNormal();
		ACharacter* Player = Cast<ACharacter>(Actor);
		
		FHitResult Hit;
		bool bHit = World->LineTraceSingleByChannel(Hit, Start, Actor->GetActorLocation(), ECC_GameTraceChannel1, Params);
		if (Hit.GetActor() == Player)
		{
			if (Player && IsValid(Player))
			{
				FVector PlayerDist = Hit.GetActor()->GetActorLocation();
				Damage = 0;
				DetectedActor = Player;
				float Distance = FVector::Dist(Start, PlayerDist);
				float Percentage = Distance / ViewDistance;
				if (Distance <= ViewDistance)
				{
					Damage = (1 - Percentage) * 100;
				}
			}
		}
		if (DebugShow == true)
		{
			DrawDebugSphere(
		World,
		Start,
		ViewDistance,
		24,
		FColor::Blue,
		false,
		5.0f,
		0,
		2.0f
	);
		}
		
	}
	
}
