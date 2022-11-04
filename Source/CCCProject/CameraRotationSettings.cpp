// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraRotationSettings.h"
#include "GizmosUtils.h"
#include "LogUtils.h"
void UCameraRotationSettings::DrawLookAtStatus(const FVector& _origin, UWorld* _world)
{
	if (!drawGizmos)
		return;

	DrawDebugSphere(_world, _origin + FVector::UpVector * 200, 50,12, useLookAt ? validLookAtColor : FColor::Red);
	DrawDebugLine(_world, _origin + FVector::UpVector * 200, _origin, FColor::White);
}

void UCameraRotationSettings::DrawLookAtTarget(FVector _targetPosition, FVector _origin, FColor _color, UWorld* _world)
{
	if (!drawGizmos)
		return;

	DrawDebugSphere(_world,	_targetPosition, 50, 12, _color);
	DrawDebugLine(_world,_origin, _targetPosition, _color);
}

 FVector UCameraRotationSettings::GetLookAtTarget(const AActor* _origin)
{
	 if (!_origin)
		 return offset.Offset();
	return offset.useLocalOffset ? offset.GetLocalOffset(_origin) : _origin->GetActorLocation() + offset.Offset();
}