// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPositionSettings.h"
#include "GizmosUtils.h"
FVector UCameraPositionSettings::GetCameraPosition(const FTransform& _origin)
{
    return FVector(0);
}

void UCameraPositionSettings::DrawCameraPosition(const FTransform& _target)
{
    DRAW_BOX(_target.GetLocation(), FVector(100), FColor::Yellow);
    //DRAW_LINE()
}

void UCameraPositionSettings::DrawMoveToStatus(FVector _origin)
{

}
