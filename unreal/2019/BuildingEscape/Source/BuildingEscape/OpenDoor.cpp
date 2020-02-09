// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "Gameframework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
  Owner = GetOwner();

  if(!PressurePlate)
  {    
    UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName());
  }
}

void UOpenDoor::OpenDoor()
{
  // set the door rotation
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoor::CloseDoor()
{
  // set the door rotation
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the trigger volume
  // if the ActorThatOpens is in the volume
  if (GetTotalMassOfActorsOnPlate() > 30.f) // TODO hard coded
  {
    OpenDoor();
    LastDoorOpenTime = GetWorld()->GetTimeSeconds();
  }

  // check if it's time to close door
  if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) 
  {
    CloseDoor();
  }
}

float UOpenDoor::GetTotalMassOfActorsOnPlate() 
{
  float TotalMass = 0.f;

  // find all the overlapping actors
  TArray<AActor*> OverlappingActors;
  if (!PressurePlate) { return TotalMass; }
  PressurePlate->GetOverlappingActors(OverlappingActors);

  // iterate through them adding ther masses
  for (const auto* Actor : OverlappingActors)
  {
    TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
  }

  return TotalMass;
}