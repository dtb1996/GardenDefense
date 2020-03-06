// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "AICharacter.h"
#include "BotTargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"

AMyAIController::AMyAIController()
{
    //Initialize BehaviorTreeComponent, BlackboardComponent and the corresponding key
 
    BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
 
    BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
 
    LocationToGoKey = "LocationToGo";
 
}
 
void AMyAIController::OnPossess(APawn* Pawn)
{
    Super::OnPossess(Pawn);
 
    //Get the possessed Character and check if it's my own AI Character
    AAICharacter* AIChar = Cast<AAICharacter>(Pawn);
 
    if (AIChar)
    {
        //If the blackboard is valid initialize the blackboard for the corresponding behavior tree
        if (AIChar->BehaviorTree->BlackboardAsset)
        {
            BlackboardComp->InitializeBlackboard(*(AIChar->BehaviorTree->BlackboardAsset));
        }
 
        /*Populate the array of available bot target points
        The following function needs a TArray of AActors, that's why I declared the
        BotTargetPoints as such. When I will need to get an exact point and compare it,
        I will cast it to the corresponding class (ABotTargetPoint)*/
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABotTargetPoint::StaticClass(), BotTargetPoints);
 
        //Start the behavior tree which corresponds to the specific character
        BehaviorComp->StartTree(*AIChar->BehaviorTree);
    }
}