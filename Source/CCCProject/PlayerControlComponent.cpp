// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControlComponent.h"

UPlayerControlComponent::UPlayerControlComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UPlayerControlComponent::BeginPlay()
{
	Super::BeginPlay();
	BindCustom();
	
}


void UPlayerControlComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveByControls();
	DrawDebug();
}

void UPlayerControlComponent::BindCustom()
{
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAxis(vAxisName, this,&UPlayerControlComponent::OnVerticalAxis);
	GetWorld()->GetFirstPlayerController()->InputComponent->BindAxis(hAxisName, this,&UPlayerControlComponent::OnHorizontalAxis);
}

void UPlayerControlComponent::MoveByControls()
{
	GetOwner()->SetActorLocation(PlayerLocation());
	if (controlSettings && controlSettings->UseRotate())
		GetOwner()->AddActorLocalRotation(PlayerRotation());
}
void UPlayerControlComponent::OnVerticalAxis(float _axis)
{
	vAxis = _axis;
}

void UPlayerControlComponent::OnHorizontalAxis(float _axis)
{
	hAxis = _axis;
}

void UPlayerControlComponent::DrawDebug()
{
	DrawDebugLine(GetWorld(), GetOwner()->GetActorLocation(), GetOwner()->GetActorLocation() + PlayerVelocity(), FColor::Red);
	DrawDebugSphere(GetWorld(), GetOwner()->GetActorLocation() + PlayerVelocity(), 20, 15, FColor::Red);
}

