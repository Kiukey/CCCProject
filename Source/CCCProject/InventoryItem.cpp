// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryItem.h"
#define DELTA_TIME GetWorld()->DeltaTimeSeconds

AInventoryItem::AInventoryItem()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

}

void AInventoryItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInventoryItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!isEnable)
		return;
	point = GetWorldLocationFromViewport(depth);
	SetItemLocation(point, target);
	DrawDebugPoint();
}

FVector AInventoryItem::GetWorldLocationFromViewport(float _depth)
{
	APlayerController* _player = GetWorld()->GetFirstPlayerController();
	if (!_player)
		return FVector();
	int32 _x, _y;
	_player->GetViewportSize(_x,_y);
	FVector _world, _dir;
	_player->DeprojectScreenPositionToWorld(_x * screenX, _y * screenY, _world, _dir);
	return _world + _dir * _depth;
}

void AInventoryItem::SetItemLocation(const FVector& _location, AActor* _item)
{
	if (!_item)
		return;
	const FVector& _loc = FMath::VInterpConstantTo(_item->GetActorLocation(), _location, DELTA_TIME, 100);
	_item->SetActorLocation(_loc);
}

void AInventoryItem::DrawDebugPoint()
{
	DrawDebugSphere(GetWorld(), point, 50, 15, FColor::Green);
}