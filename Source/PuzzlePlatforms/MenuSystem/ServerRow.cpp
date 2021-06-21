// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerRow.h"
#include "Components/Button.h"
#include "MainMenu.h"
#include "Components/TextBlock.h"

void UServerRow::Setup(class UMainMenu * Parent, uint32 Index)
{
	this->Parent = Parent;
	this->Index = Index;

	RowButton->OnClicked.AddDynamic(this, &UServerRow::OnClicked);
}

void UServerRow::OnClicked()
{
	Parent->SelectIndex(Index);
}
