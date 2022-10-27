// Fill out your copyright notice in the Description page of Project Settings.


#include "SmoothFollowActor.h"

ASmoothFollowActor::ASmoothFollowActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	moveComponent = CreateDefaultSubobject<UFollowSmoothMoveComponent>("SmoothMoveComponent");
	AddOwnedComponent(moveComponent);
}

void ASmoothFollowActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASmoothFollowActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

