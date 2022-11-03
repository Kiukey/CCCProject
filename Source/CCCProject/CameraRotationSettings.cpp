// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraRotationSettings.h"
#include "GizmosUtils.h"
void UCameraRotationSettings::DrawLookAtStatus(const FVector& _origin)
{
	if (!drawGizmos)
		return;

	DRAW_SPHERE(_origin + FVector::UpVector * 200, 50,12, useLookAt ? validLookAtColor : FColor::Red);
	DRAW_LINE(_origin + FVector::UpVector * 200, _origin, FColor::White);
}

void UCameraRotationSettings::DrawLookAtTarget(FVector _targetPosition, FVector _origin, FColor _color)
{
	if (!drawGizmos)
		return;

	DRAW_SPHERE(_targetPosition, 50, 12, _color);
	DRAW_LINE(_origin, _targetPosition, _color);
}