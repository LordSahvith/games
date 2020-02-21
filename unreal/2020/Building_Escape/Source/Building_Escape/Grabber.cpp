// Copyright 2020 Lord Sahvith

#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}

// Called when the game starts
void UGrabber::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Grabber grabbing things."));
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // get players viewpoint
    FVector PLayerViewPointLocation;
    FRotator PlayerViewPointRotation;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
        OUT PLayerViewPointLocation,
        OUT PlayerViewPointRotation);

    // draw a line from player showing the reach
    FVector LineTraceEnd = PLayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

    DrawDebugLine(
        GetWorld(),
        PLayerViewPointLocation,
        LineTraceEnd,
        FColor(255, 0, 0),
        false,
        0.f,
        0,
        5.f);

    // ray-cast out to a certain distance (reach)
    FHitResult Hit;
    FCollisionQueryParams TraceParms(FName(TEXT("")), false, GetOwner());

    GetWorld()->LineTraceSingleByObjectType(
        OUT Hit,
        PLayerViewPointLocation,
        LineTraceEnd,
        FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
        TraceParms);

    // see what it hits
    AActor *ActorHit = Hit.GetActor();

    if (ActorHit)
    {
        UE_LOG(LogTemp, Warning, TEXT("Grabbing %s"), *(ActorHit->GetName()));
    }
}
