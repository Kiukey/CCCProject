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
	if (!IsValidComponent())
	{
		DrawDebugBox(_w, CurrentPosition(),FVector(100),FColor::Red);
		return;
	}
	DrawDebugLine(_w, CurrentPosition(), settings.TargetPosition(), FColor::Green);
	DrawDebugSphere(_w , CurrentPosition(), 100, 12, FColor::Green);
	DrawDebugSphere(_w , settings.TargetPosition(), 100, 12, FColor::Green);
	DrawDebugCircle(_w , settings.TargetPosition(), settings.range, 30, FColor::Magenta, false ,-1,0,2,FVector(1,0,0),FVector(0,1,0));
}

