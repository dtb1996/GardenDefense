// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupActor.h"

// Sets default values
APickupActor::APickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create all components
	this->SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	this->RootComponent = SceneComponent;

	this->ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	this->ItemMesh->AttachTo(this->RootComponent);

	this->RotationRate = FRotator(0.0f, 180.0f, 0.0f);

	this->Speed = 1.0f;

	//Create collider
	this->BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	this->BoxCollider->SetGenerateOverlapEvents(true);
	this->BoxCollider->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	this->BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &APickupActor::OnOverlapBegin);
	this->BoxCollider->AttachToComponent(this->RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

//Overlap handler
void APickupActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Check if the OtherActor is not me and if it is not NULL
	if((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		FString pickup = FString::Printf(TEXT("Picked up: %s"), *GetName());

		GEngine->AddOnScreenDebugMessage(1, 5, FColor::White, pickup);

		Destroy();
	}
}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Rotate the object (local rotation)
	this->AddActorLocalRotation(this->RotationRate * DeltaTime * Speed);



}

