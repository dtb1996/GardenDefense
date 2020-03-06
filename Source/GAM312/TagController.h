// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "TagController.generated.h"

/**
 * 
 */
UCLASS()
class GAM312_API ATagController : public AAIController
{
	GENERATED_BODY()

public:
    void BeginPlay() override;

private:
    UPROPERTY()
        TArray<AActor*> Waypoints;

    UFUNCTION()
        ATargetPoint* GetRandomWaypoint();

    UFUNCTION()
        void GoToRandomWaypoint();

public:
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

private:
	FTimerHandle TimerHandle;
	
};
