// Fill out your copyright notice in the Description page of Project Settings.


#include "BossMovement.h"

void UBossMovement::BossFight(UObject* WorldContextObject, AActor* Actor, bool Move, float Time)
{
	if (Move == true)
	{
		FRotator DeltaRotate = FRotator(0.0f, 20.0f * Time, 0.0f);
		Actor->AddActorLocalRotation(DeltaRotate);
		
	}
}
void UBossMovement::LookAtPlayer(UObject* WorldContextObject, AActor* Actor, AActor* SecActor)
{
	if (!IsValid(Actor)) return;
	if (!IsValid(SecActor)) return;
	FVector Location = SecActor->GetActorLocation();
	FVector Start = Actor->GetActorLocation();
	FRotator LookAtRotate = (Location - Start).Rotation();
	LookAtRotate.Pitch = 0.0f;
	LookAtRotate.Roll = 0.0f;
	FRotator Current = Actor->GetActorRotation();
	LookAtRotate = FMath::RInterpTo(Current, LookAtRotate, WorldContextObject->GetWorld()->GetDeltaSeconds(), 2.0f);
	
	Actor->SetActorRotation(LookAtRotate);
}
void UBossMovement::LookAtPlayerAmmo(UObject* WorldContextObject, AActor* Actor, FVector Location)
{
	if (!IsValid(Actor)) return;
	FVector Start = Actor->GetActorLocation();
	FRotator LookAtRotate = (Location - Start).Rotation();
	LookAtRotate.Pitch = 0.0f;
	LookAtRotate.Roll = 0.0f;
	FRotator Current = Actor->GetActorRotation();
	Actor->SetActorRotation(LookAtRotate);
}
