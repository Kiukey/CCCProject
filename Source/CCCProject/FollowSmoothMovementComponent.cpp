// Fill out your copyright notice in the Description page of Project Settings.


#include "FollowSmoothMovementComponent.h"
#include "LogUtils.h"
#include "GizmosUtils.h"

UFollowSmoothMovementComponent::UFollowSmoothMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}
void UFollowSmoothMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	//LOG("OK");
	//LOG_WARNING("Warning");
	//LOG_ERROR("ERROR");
	//SCREEN_MSG("Test", 5, FColor::Blue);
}
void UFollowSmoothMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveToTarget_Implementation();
	DrawDebug();
	/*DRAW_SPHERE(GetOwner()->GetActorLocation(), 250, 15, FColor::Black);
	DRAW_BOX(GetOwner()->GetActorLocation(), FVector(50), FColor::Red);
	DRAW_CIRCLE(settings.TargetPosition(), 500, 30, FColor::Black, FVector(1, 0, 0), FVector(0, 1, 0))*/
}
void UFollowSmoothMovementComponent::MoveToTarget_Implementation()
{
	//GetClass()->ImplementsInterface(UMove::StaticClass());
	//IF TRUE
	//TScriptInterface<IMove> _int;
	//_int.SetInterface(Cast<IMove>(this));
	//_int.SetObject(this);
	//if (_int != nullptr)
	//	_int->Execute_MoveToTarget(this);
	//

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

