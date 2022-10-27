// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowConstMoveComponent.h"

UFollowConstMoveComponent::UFollowConstMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UFollowConstMoveComponent::BeginPlay()
{
	Super::BeginPlay();


	
}


void UFollowConstMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FollowTargetConst();
	DrawDebug();
}

void UFollowConstMoveComponent::FollowTargetConst()
{
	if (!moveSettings.target || moveSettings.isStopped)
		return;
	FVector _targetPos = moveSettings.target->GetActorLocation();
	FVector _currentPos = GetOwner()->GetActorLocation();
	FVector _newPos = FMath::VInterpConstantTo(_currentPos, _targetPos, GetWorld()->DeltaTimeSeconds, moveSettings.moveSpeed);
	
	
	GetOwner()->SetActorLocation(_newPos);
}

void UFollowConstMoveComponent::DrawDebug()
{
	if (!moveSettings.target || !debugSettings.useDebug)
		return;

	FVector _targetPos = moveSettings.target->GetActorLocation();
	DrawDebugSphere(GetWorld(), _targetPos, debugSettings.sphereRadius, debugSettings.debugSegment, debugSettings.debugColor);
	DrawDebugSphere(GetWorld(), GetOwner()->GetActorLocation(),debugSettings.sphereRadius, debugSettings.debugSegment,debugSettings.debugColor);
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), _targetPos, debugSettings.debugColor);
}
