// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ServerRow.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UServerRow : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(Meta=(BindWidget))
	class UTextBlock* ServerName;

	UPROPERTY(Meta = (BindWidget))
	class UTextBlock* HostUser;


	UPROPERTY(Meta = (BindWidget))
	class UTextBlock* ConnectionFraction;


	UPROPERTY(BlueprintReadOnly)
	bool bSelected = false;


	void Setup(class UMainMenu* Parent, uint32 Index);

private:
	UPROPERTY(Meta = (BindWidget))
	class UButton* RowButton;

	UPROPERTY()
	class UMainMenu* Parent;

	uint32 Index;

	UFUNCTION()
	void OnClicked();
	
};
