// Fill out your copyright notice in the Description page of Project Settings.


#include "SetViewTargetWithBlend.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASetViewTargetWithBlend::ASetViewTargetWithBlend()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASetViewTargetWithBlend::BeginPlay()
{
	Super::BeginPlay();

	//APlayerController* OurPlayer = UGameplayStatics::GetPlayerController(this, 0);

	//OurPlayer->SetViewTargetWithBlend(MyActor, 4.f);
	
}

// Called every frame
void ASetViewTargetWithBlend::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

