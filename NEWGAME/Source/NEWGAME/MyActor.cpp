// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

#include "Components/SpotLightComponent.h"

// Sets default values
AMyActor::AMyActor()
{
	
 	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh -> SetupAttachment(RootComponent);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Script/Engine.StaticMesh'/Game/Hanger_Mesh/KEY.KEY'"));
	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh -> SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh -> SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh -> SetWorldScale3D(FVector(1.0f , 1.0f , 1.0f));
	}
	PrimaryActorTick.bCanEverTick = true;
	

	
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	OriginalLocation = GetActorLocation();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	RunningTime += DeltaTime;
	float DeltaHeight = FMath::Sin(RunningTime * 2.0f) * 20.0f  * DeltaTime;
	AddActorWorldOffset(FVector(0.0f, 0.0f, DeltaHeight));
	
	FRotator DeltaRotation = FRotator(0.0f, 30.0f * DeltaTime, 0.0f);
	AddActorLocalRotation(DeltaRotation);
	
}


