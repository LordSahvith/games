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

    SetupDoorSwingValues();
    FindPressurePlate();
    FindAudioComponent();
}

void UOpenDoor::SetupDoorSwingValues()
{
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

    if (TotalMassOfActors() > MassToOpenDoors)
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

    if (!AudioComponent) { return; }
    if (!AudioComponent->IsPlaying())
    {
        AudioComponent->Play();
    }
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
    CurrentYaw = FMath::Lerp(CurrentYaw, InitialYaw, DeltaTime * DoorCloseSpeed);
    FRotator DoorRotation = GetOwner()->GetActorRotation();
    DoorRotation.Yaw = CurrentYaw;
    GetOwner()->SetActorRotation(DoorRotation);
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
    }

    return TotalMass;
}