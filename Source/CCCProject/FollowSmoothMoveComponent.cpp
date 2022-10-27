// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowSmoothMoveComponent.h"
#include "DrawDebugHelpers.h"

UFollowSmoothMoveComponent::UFollowSmoothMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UFollowSmoothMoveComponent::BeginPlay()
{
	Super::BeginPlay();

}


void UFollowSmoothMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	FollowTargetSmooth();
	DrawDebug();
}

void UFollowSmoothMoveComponent::FollowTargetSmooth()
{
	if (!moveSettings.target || moveSettings.isStopped)
		return;
	
	FVector _targetPos = moveSettings.target->GetActorLocation();
	FVector _ownerPos = GetOwner()->GetActorLocation();
	FVector _currentPos = FMath::Lerp<FVector>(_ownerPos, _targetPos , GetWorld()->DeltaTimeSeconds * moveSettings.moveSpeed);

	GetOwner()->SetActorLocation(_currentPos);
}

void UFollowSmoothMoveComponent::DrawDebug()
{
	if (!moveSettings.target || !debugSettings.useDebug)
		return;

	FVector _targetPos = moveSettings.target->GetActorLocation();
	DrawDebugSphere(GetWorld(), _targetPos, debugSettings.sphereRadius, debugSettings.debugSegment, debugSettings.debugColor);
	DrawDebugSphere(GetWorld(), GetOwner()->GetActorLocation(), debugSettings.sphereRadius, debugSettings.debugSegment, debugSettings.debugColor);
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), _targetPos, debugSettings.debugColor);
}
