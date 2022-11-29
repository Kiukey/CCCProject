// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputManager.h"
#include "TestInput.generated.h"

UCLASS()
class CCCPROJECT_API ATestInput : public AActor
{
	GENERATED_BODY()

public:	
	ATestInput();

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Test();
	void TestRepeat();
	void AxisTest(float _axis);
	void Init();
};
