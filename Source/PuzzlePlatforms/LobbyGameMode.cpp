// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "PuzzlePlatformGameInstance.h"

void ALobbyGameMode::PostLogin(APlayerController * NewPlayer)
{
	Super::PostLogin(NewPlayer);

	++NumberOfPlayers;
	if (NumberOfPlayers >= 2)
	{
		GetWorldTimerManager().SetTimer(GameStartTimer, this, &ALobbyGameMode::StartGame, 10.f);

	}
}

void ALobbyGameMode::Logout(AController * Exiting)
{
	Super::Logout(Exiting);

	--NumberOfPlayers;
}

void ALobbyGameMode::StartGame()
{

	auto GameInst = Cast<UPuzzlePlatformGameInstance>(GetGameInstance());
	if (GameInst == nullptr) return;

	GameInst->StartSession();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr))return;

	bUseSeamlessTravel = true; //  use seamless travel when true, false non seamless (there is default travel map can add own)
	World->ServerTravel("/Game/Maps/Game?listen"); //non seamless travel block all, no transition map, look bad

	//UE_LOG(LogTemp,Warning,TEXT("Number of Player 3"));
}
