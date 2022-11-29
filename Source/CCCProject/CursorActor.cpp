// Fill out your copyright notice in the Description page of Project Settings.


#include "CursorActor.h"

ACursorActor::ACursorActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
}

void ACursorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACursorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!isEnable)
		return;
	point = GetWorldLocationFromMouse(depth);
	UpdateLocation(target, point);
	DrawDebugPoint();
}

FVector ACursorActor::GetWorldLocationFromMouse(float _depth)
{
	APlayerController* _player = GetWorld()->GetFirstPlayerController();
	if (!_player)
		return FVector(0);
	FVector _world, _dir;
	_player->DeprojectMousePositionToWorld(_world, _dir);
	return _world + _dir * _depth;
}

void ACursorActor::UpdateLocation(AActor* _object, const FVector& _point)
{
	if (!_object)
		return;
	_object->SetActorLocation(_point);
}

void ACursorActor::DrawDebugPoint()
{
	DrawDebugSphere(GetWorld(), point, 50, 15, FColor::Green);
}

