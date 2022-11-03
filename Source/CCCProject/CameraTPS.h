// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "GizmosUtils.h"
#include "Components/BillboardComponent.h"
#include "CameraTPS.generated.h"

USTRUCT()
struct FCameraOffset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		float xOffset = 0;
	UPROPERTY(EditAnywhere)
		float yOffset = 0;
	UPROPERTY(EditAnywhere)
		float zOffset = 0;
public:
	UPROPERTY(EditAnywhere)
		bool useLocalOffset = true;


	FORCEINLINE FVector GetOffset() { return FVector(xOffset, yOffset, zOffset); }
	FORCEINLINE FVector GetLocalOffset(AActor* _ref)
	{
		FVector _offsetLocal = FVector(0);
		_offsetLocal = _ref->GetActorLocation() +
			_ref->GetActorRightVector() * yOffset +
			_ref->GetActorForwardVector() * xOffset +
			_ref->GetActorUpVector() * zOffset;
		return _offsetLocal;
	}
};


USTRUCT()
struct FCameraPositionSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		float positionSpeed = 10;
	UPROPERTY(EditAnywhere)
		bool drawGizmos = true;
	UPROPERTY(EditAnywhere)
		bool useMoveTo = true;
	UPROPERTY(EditAnywhere)
		FColor validMoveToColor = FColor::Yellow;
	UPROPERTY(EditAnywhere)
		bool useSmoothMoveTo = true;
	UPROPERTY(EditAnywhere, Category = "Camera offset")
		FCameraOffset offset;
	
public : 

	FORCEINLINE FVector GetCameraPosition(AActor* _origin)
	{
		return offset.useLocalOffset ? offset.GetLocalOffset(_origin) : _origin->GetActorLocation() + offset.GetOffset();
	}

	FORCEINLINE void SetGizmosEnable(bool _state)
	{
		drawGizmos = _state;
	}

	FORCEINLINE void DrawCameraPosition(UWorld* _world, AActor* _target)
	{
		if (!drawGizmos)
			return;
		DrawDebugBox(_world,GetCameraPosition( _target), FVector(0.5f), validMoveToColor);
		DrawDebugLine(_world,GetCameraPosition(_target), _target->GetActorLocation(), validMoveToColor);
	}
	FORCEINLINE void DrawMoveToStatus(UWorld* _world, FVector _origin)
	{
		if (!drawGizmos)
			return;
		DrawDebugSphere(_world,_origin + FVector::UpVector * 1.5f, 80, 15, useMoveTo ? validMoveToColor : FColor::Red);
		DrawDebugLine(_world,_origin, _origin + FVector::UpVector * 2, FColor::White);
	}
};
USTRUCT()
struct FCameraRotationSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		float rotationSpeed = 10;
	UPROPERTY(EditAnywhere)
		bool drawGizmos = true;
	UPROPERTY(EditAnywhere)
		bool useLookAt = true;
	UPROPERTY(EditAnywhere)
		FColor validLookAtColor = FColor::Yellow;
	UPROPERTY(EditAnywhere)
		bool useSmoothLookAt = true;
	UPROPERTY(EditAnywhere, Category = "Camera offset")
		FCameraOffset offset;

public:

	FORCEINLINE FVector GetLookAtTarget(AActor* _origin)
	{
		return offset.useLocalOffset ? offset.GetLocalOffset(_origin) : _origin->GetActorLocation() + offset.GetOffset();
	}

	FORCEINLINE void SetGizmosEnable(bool _state)
	{
		drawGizmos = _state;
	}
	//TODO les debugs mais y'a un prob
	FORCEINLINE void DrawLookAtTarget(UWorld* _world, FVector _target, FVector _origin)
	{
		if (!drawGizmos)
			return;
		DrawDebugSphere(_world, _target, 80, 15,validLookAtColor);
		DrawDebugLine(_world, _target, _origin, validLookAtColor);
	}
	FORCEINLINE void DrawLookAtStatus(UWorld* _world, FVector _origin)
	{
		if (!drawGizmos)
			return;
		DrawDebugSphere(_world, _origin + FVector::UpVector * 1.5f, 80, 15, useLookAt ? validLookAtColor : FColor::Red);
		DrawDebugLine(_world, _origin, _origin + FVector::UpVector * 2, FColor::White);
	}
};



UCLASS()
class CCCPROJECT_API ACameraTPS : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> target = nullptr;
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* currentCamera = nullptr;
	UPROPERTY(EditAnywhere, Category = " Settings | Look at Settings")
		FCameraRotationSettings lookAtSettings;
	UPROPERTY(EditAnywhere, Category = "Settings | Move to Settings")
		FCameraPositionSettings positionSettings;
	UPROPERTY(EditAnywhere)
		bool useDebug = true;
	UPROPERTY(EditAnywhere)
		UBillboardComponent* billboardComponent = nullptr;
public:	
	ACameraTPS();

private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE bool IsCameraTPSValid() { return target != nullptr; }
	void MoveToTarget();
	void LookAtTarget();
	void DrawDebug();
	void ActivateCamera();
};
