// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowSmoothMovementComponent.h"

UFollowSmoothMovementComponent::UFollowSmoothMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}
void UFollowSmoothMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	
}
void UFollowSmoothMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveToTarget();
	DrawDebug();
}
void UFollowSmoothMovementComponent::MoveToTarget()
{
	if (!IsValidComponent() || settings.IsAtRange(CurrentPosition()))
		return;
	const FVector _move = FMath::Lerp(CurrentPosition(), settings.TargetPosition(), settings.speed * GetWorld()->DeltaTimeSeconds);
	//VInterpToConst
	GetOwner()->SetActorLocation(_move);
}
void UFollowSmoothMovementComponent::DrawDebug()
{
	const UWorld* _w = GetWorld();
	if (!IsValidComponent()|| !debugSettings.useDebug)
	{
		DrawDebugBox(_w, CurrentPosition(),FVector(100),FColor::Red);
		return;
	}
	DrawDebugLine(_w, CurrentPosition(), settings.TargetPosition(), debugSettings.debugColor);
	DrawDebugSphere(_w , CurrentPosition(), debugSettings.sphereRadius, debugSettings.debugSegment, debugSettings.debugColor);
	DrawDebugSphere(_w , settings.TargetPosition(), debugSettings.sphereRadius, debugSettings.debugSegment, debugSettings.debugColor);
	DrawDebugCircle(_w , settings.TargetPosition(), settings.range, 30, debugSettings.debugColor, false ,-1,0,2,FVector(1,0,0),FVector(0,1,0));
}

