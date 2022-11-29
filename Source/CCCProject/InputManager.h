#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputSettingsAsset.h"
#include "LogUtils.h"
#include "InputManager.generated.h"


UCLASS()
class CCCPROJECT_API AInputManager : public AActor
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = InputSettings)
		TObjectPtr<UInputSettingsAsset> currentInputSettings = nullptr;

public:	
	AInputManager();
	template<class TypeClass>
	void BindAction(const EButtonAction& _action, TypeClass* _owner, typename FInputActionHandlerSignature::TUObjectMethodDelegate<TypeClass>::FMethodPtr _method)
	{
		for (int i = 0; i < currentInputSettings->GetAllButtons().Num(); i++)
		{
			FButtonStruct _button = currentInputSettings->GetAllButtons()[i];
			//if (!_button)
			//	continue;
			if (_button.buttonAction == _action)
			{
				APlayerController* _pc = GetWorld()->GetFirstPlayerController();
				if (!_pc)
					continue;
				for (int y = 0; y < _button.buttonsKeyCode.Num(); y++)
				{
					FInputActionKeyMapping _key = FInputActionKeyMapping(_button.actionName, _button.buttonsKeyCode[y]);
					_pc->PlayerInput->AddActionMapping(_key);
				}
					_pc->InputComponent->BindAction(_button.actionName, _button.buttonState, _owner, _method);

			}
		}
	}
	template<class TypeClass>
	void BindAxis(const EButtonAction& _axis, TypeClass* _owner, typename FInputAxisHandlerSignature::TUObjectMethodDelegate<TypeClass>::FMethodPtr _method)
	{
		for (int i = 0; i < currentInputSettings->GetAllAxis().Num(); i++)
		{
			FAxisStruct _currentAxis = currentInputSettings->GetAllAxis()[i];
			//if (!_currentAxis)
			//	return;
			if (_currentAxis.axisAction == _axis)
			{
				APlayerController* _pc = GetWorld()->GetFirstPlayerController();
				if (!_pc)
					return;
				//FInputAxisKeyMapping _key = FInputAxisKeyMapping(_currentAxis->axisName, _currentAxis->buttonKeyCode, _currentAxis->scale);
				//_pc->PlayerInput->AddAxisMapping(_key);
				//_pc->InputComponent->BindAxis(_currentAxis->axisName, _owner, _method);
				////
				const int _num = _currentAxis.axisKeyCode.Num();
				for (int y = 0; y < _num; y++)
				{
					FInputAxisKeyMapping _key = FInputAxisKeyMapping(_currentAxis.axisName, _currentAxis.axisKeyCode[y].axis, _currentAxis.axisKeyCode[y].scale);
					_pc->PlayerInput->AddAxisMapping(_key);
				}
				_pc->InputComponent->BindAxis(_currentAxis.axisName, _owner, _method);
			}
			
		}
	}

};
