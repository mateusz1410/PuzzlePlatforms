// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FORCEINLINE void SetMenuInterface(IMenuInterface* MenuInterface) { this->MenuInterface = MenuInterface; }

	void Setup();
	void Teardown();


protected:
	IMenuInterface* MenuInterface;


};
