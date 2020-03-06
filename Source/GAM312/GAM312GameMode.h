// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GAM312Character.h"
#include "GAM312GameMode.generated.h"

UENUM()
enum class EGamePlayState
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class AGAM312GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGAM312GameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	AGAM312Character* MyCharacter;

	UFUNCTION(BlueprintPure, Category = "Health")
	EGamePlayState GetCurrentState() const;

	void SetCurrentState(EGamePlayState NewState);

private:

	EGamePlayState CurrentState;

	void HandleNewState(EGamePlayState NewState);
};



