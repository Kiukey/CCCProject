// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstFollowActor.h"

AConstFollowActor::AConstFollowActor()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	moveComponent = CreateDefaultSubobject<UFollowConstMoveComponent>("ConstMoveComponent");
	AddOwnedComponent(moveComponent);
}

void AConstFollowActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AConstFollowActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

