// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GAM312GameMode.h"
#include "GAM312HUD.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GAM312Character.h"
#include "UObject/ConstructorHelpers.h"

AGAM312GameMode::AGAM312GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGAM312HUD::StaticClass();
}

void AGAM312GameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<AGAM312Character>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AGAM312GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(MyCharacter)
	{
		if(FMath::IsNearlyZero(MyCharacter->GetHealth(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
		}
	}
}

EGamePlayState AGAM312GameMode::GetCurrentState() const
{
	return CurrentState;
}

void AGAM312GameMode::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void AGAM312GameMode::HandleNewState(EGamePlayState NewState)
{
	switch(NewState)
	{
		case EGamePlayState::EPlaying:
		{
			//Do nothing
		}
		break;

		case EGamePlayState::EGameOver:
		{
			UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
		}
		break;

		default:
		case EGamePlayState::EUnknown:
		{
			//Do nothing
		}
		break;
	}
}