// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FollowSmoothMoveComponent.generated.h"

USTRUCT()
struct FMoveSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		AActor* target = nullptr;
	UPROPERTY(EditAnywhere)
		float moveSpeed = 1;
	UPROPERTY(EditAnywhere)
		bool isStopped = false;

	FORCEINLINE void StopMovement() { isStopped = true; }
	FORCEINLINE void ResumeMovement() { isStopped = false; }
	FORCEINLINE AActor* GetTarget() { return target; }

};
USTRUCT()
struct FDebugSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		float sphereRadius = 20;	
	UPROPERTY(EditAnywhere)
		float debugSegment = 20;
	UPROPERTY(EditAnywhere)
		FVector boxSize = FVector(25);
	UPROPERTY(EditAnywhere)
		FColor debugColor = FColor::Red;
	UPROPERTY(EditAnywhere)
		bool useDebug = true;

};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CCCPROJECT_API UFollowSmoothMoveComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		FMoveSettings moveSettings;
	UPROPERTY(EditAnywhere)
		FDebugSettings debugSettings;
public:	
	UFollowSmoothMoveComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	void FollowTargetSmooth();
	void DrawDebug();
};
