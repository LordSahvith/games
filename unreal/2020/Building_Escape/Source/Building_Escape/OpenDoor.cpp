// Copyright 2020 Lord Sahvith

#include "OpenDoor.h"
#include "Components/AudioComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
    Super::BeginPlay();

    SetupDoorOpenOptions();
    FindPressurePlate();
    FindAudioComponent();
}

void UOpenDoor::SetupDoorOpenOptions()
{
    if (!ActorThatOpens)
    {
        UE_LOG(LogTemp, Error, TEXT("%s doesn't have ActorThatOpens set."), *GetOwner()->GetName());
        ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
    }
    InitialYaw = GetOwner()->GetActorRotation().Yaw;
    CurrentYaw = InitialYaw;
    OpenAngle += InitialYaw;
}

void UOpenDoor::FindPressurePlate()
{
    if (!PressurePlate)
    {
        UE_LOG(LogTemp, Error, TEXT("%s has no pressure plate assigned!"), *GetOwner()->GetName());
    }
}

void UOpenDoor::FindAudioComponent()
{
    AudioComponent = GetOwner()->FindComponentByClass<UAudioComponent>();

    if (!AudioComponent)
    {
        UE_LOG(LogTemp, Error, TEXT("%s missing audio component."), *GetOwner()->GetName());
    }
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (TotalMassOfActors() > MassToOpenDoors || (PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens)))
    {
        OpenDoor(DeltaTime);
        DoorLastOpened = GetWorld()->GetTimeSeconds();
    }
    else
    {
        if (GetWorld()->GetTimeSeconds() - DoorLastOpened > DoorCloseDelay)
        {
            CloseDoor(DeltaTime);
        }
    }
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
    CurrentYaw = FMath::Lerp(CurrentYaw, OpenAngle, DeltaTime * DoorOpenSpeed);
    FRotator DoorRotation = GetOwner()->GetActorRotation();
    DoorRotation.Yaw = CurrentYaw;
    GetOwner()->SetActorRotation(DoorRotation);

    bCloseDoorSound = false;
    if (!AudioComponent) { return; }
    if (!bOpenDoorSound)
    {
        AudioComponent->Play();
        bOpenDoorSound = true;
    }
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
    CurrentYaw = FMath::Lerp(CurrentYaw, InitialYaw, DeltaTime * DoorCloseSpeed);
    FRotator DoorRotation = GetOwner()->GetActorRotation();
    DoorRotation.Yaw = CurrentYaw;
    GetOwner()->SetActorRotation(DoorRotation);

    bOpenDoorSound = false;
    if (!AudioComponent) { return; }
    if (!bCloseDoorSound)
    {
        AudioComponent->Play();
        bCloseDoorSound = true;
    }
}

float UOpenDoor::TotalMassOfActors() const
{
    float TotalMass = 0.f;

    // find all overlapping actors
    TArray<AActor *> OverlappingActors;
    if (!PressurePlate) { return TotalMass; }
    PressurePlate->GetOverlappingActors(OUT OverlappingActors);

    // add up their masses
    for (AActor *Actor : OverlappingActors)
    {
        TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
        UE_LOG(LogTemp, Warning, TEXT("%s is on the pressure plate."), *Actor->GetName());
    }

    return TotalMass;
}