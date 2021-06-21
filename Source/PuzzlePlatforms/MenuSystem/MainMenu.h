// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuSystem/MenuWidget.h"
#include "MainMenu.generated.h"


 USTRUCT()
struct FServerData
{
	 GENERATED_BODY()

	 FString Name;
	 uint16 CurrentPlayers;
	 uint16 MaxPlayers;
	 FString HostUsername;
};
/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:
	UMainMenu(const FObjectInitializer&  ObjectInitializer);
	void SetServerList(TArray<FServerData> ServerNames);

	void SelectIndex(uint32 Index);

private:

	TSubclassOf<class UUserWidget>ServerRowClass;
	class UServerRow* ServerRow;

	UPROPERTY(Meta = (BindWidget))
	class UButton* HostButton; // bind with variable name (component) by name
	
	UPROPERTY(Meta = (BindWidget))
	class UButton* JoinButton; // name need to be same

	UPROPERTY(Meta = (BindWidget))
	class UButton* CancelJoinMenuButton; // name need to be same

	UPROPERTY(Meta = (BindWidget))
	class UButton* ConfirmJoinMenuButton; // name need to be same

	UPROPERTY(Meta = (BindWidget))
	class UButton* QuitButton;

	UPROPERTY(Meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(Meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(Meta = (BindWidget))
	class UWidget* HostMenu;

	UPROPERTY(Meta = (BindWidget))
	class UEditableTextBox* ServerHostName;

	UPROPERTY(Meta = (BindWidget))
	class UButton* CancelHostMenuButton;

	UPROPERTY(Meta = (BindWidget))
	class UButton* ConfirmHostMenuButton;

	UPROPERTY(Meta = (BindWidget))
	class UWidget* MainMenu;

	UPROPERTY(Meta = (BindWidget))
	class UPanelWidget* ServerList;

protected:
	virtual bool Initialize() override; // use bind widget

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void OpenHostMenu();

	UFUNCTION()
	void OpenMainMenu();

	UFUNCTION()
	void QuitGame();

	TOptional<uint32> SelectedIndex;// type uint32, can be null

	void UpdateChildren();

};
