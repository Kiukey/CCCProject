// Fill out your copyright notice in the Description page of Project Settings.


#include "TestInput.h"
#include "InputGameModeBase.h"

ATestInput::ATestInput()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
}

void ATestInput::BeginPlay()
{
	Super::BeginPlay();

	Init();
}

void ATestInput::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATestInput::Test()
{
	UE_LOG(LogTemp, Warning, TEXT("Ok TEST"));
}

void ATestInput::TestRepeat()
{
	UE_LOG(LogTemp, Warning, TEXT("Ok TEST Repeat"));
}

void ATestInput::AxisTest(float _axis)
{
	if(_axis != 0)
		UE_LOG(LogTemp, Warning, TEXT("%f"), _axis);
}

void ATestInput::Init()
{
	AInputGameModeBase* _gm = GetWorld()->GetAuthGameMode<AInputGameModeBase>();
	if (!_gm)
		return;
	AInputManager* _refInputManager = _gm->GetInputManager();
	if (!_refInputManager)
		return;
	_refInputManager->BindAction(EButtonAction::JUMP, this, &ATestInput::Test);
	_refInputManager->BindAction(EButtonAction::MOVE_FORWARD, this, &ATestInput::TestRepeat);
	_refInputManager->BindAxis(EButtonAction::MOVE_FORWARD, this, &ATestInput::AxisTest);
}

