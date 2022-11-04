// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPositionSettings.h"
#include "GizmosUtils.h"
FVector UCameraPositionSettings::GetCameraPosition(const AActor* _target) const
{
    return offset.useLocalOffset ? offset.GetLocalOffset(_target) : _target->GetActorLocation() + offset.Offset() ;
}

void UCameraPositionSettings::DrawCameraPosition(const FTransform& _target, UWorld* _world)
{
    DrawDebugBox(_world, _target.GetLocation(), FVector(100), FColor::Yellow);
    //DRAW_LINE()
}

void UCameraPositionSettings::DrawMoveToStatus(FVector _origin, UWorld* _world)
{

}
