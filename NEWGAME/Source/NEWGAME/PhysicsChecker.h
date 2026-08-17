

#pragma once
#include "GameFramework/Character.h"
#include "Engine/OverlapResult.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PhysicsChecker.generated.h"


/**
 * 
 */
UCLASS()
class NEWGAME_API UPhysicsChecker : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable, Category = "Trace", meta = (WorldContext = "WorldContextObject"))
	static bool LineTrace(
							UObject* WorldContextObject,
							USceneComponent* FirePoint,
							float ViewDistance,
							float ViewAngle,
							AActor*& DetectedActor,
							FRotator& ActorRotate,
							bool DebugShow);
	UFUNCTION(BlueprintCallable, Category = "Trace", meta = (WorldContext = "WorldContextObject"))
	static void LookAtPlayerNPC(UObject* WorldContextObject, AActor* Actor, AActor* SecActor, float InterpSpeed = 0.5f);
};

