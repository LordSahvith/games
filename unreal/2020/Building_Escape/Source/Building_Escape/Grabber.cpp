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
}

// Called when the game starts
void UGrabber::BeginPlay()
{
    Super::BeginPlay();
    FindPhysicsHandle();
    SetupInputComponent();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // if the phsyics handle is atttached
    if (PhysicsHandle->GrabbedComponent)
    {
        // move the object we are holding
        PhysicsHandle->SetTargetLocation(GetPlayerReach());
    }
    
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
    // ray-cast out to a certain distance (reach)
    FHitResult Hit;
    FCollisionQueryParams TraceParms(FName(TEXT("")), false, GetOwner());

    GetWorld()->LineTraceSingleByObjectType(
        OUT Hit,
        GetPlayersWorldPos(),
        GetPlayerReach(),
        FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
        TraceParms);

    return Hit;
}

// check for a physics handle component
void UGrabber::FindPhysicsHandle()
{
    PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

    if (!PhysicsHandle)
    {
        UE_LOG(LogTemp, Error, TEXT("%s has no physics handle component."), *GetOwner()->GetName());
    }
}

void UGrabber::SetupInputComponent()
{
    InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
    if (InputComponent)
    {
        InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
        InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Input component missing on %s"), *GetOwner()->GetName());
    }
}

void UGrabber::Grab()
{
    FHitResult HitResult = GetFirstPhysicsBodyInReach();
    UPrimitiveComponent *ComponentToGrab = HitResult.GetComponent();

    // if we hit something then attach the physics handle
    if (HitResult.GetActor())
    {
        PhysicsHandle->GrabComponentAtLocation(
            ComponentToGrab,
            NAME_None,
            GetPlayerReach());
    }
}

void UGrabber::Release()
{
    PhysicsHandle->ReleaseComponent();
}

FVector UGrabber::GetPlayerReach() const 
{
    // get players viewpoint
    FVector PLayerViewPointLocation;
    FRotator PlayerViewPointRotation;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
        OUT PLayerViewPointLocation,
        OUT PlayerViewPointRotation);

    // draw a line from player showing the reach
    return PLayerViewPointLocation;
}

FVector UGrabber::GetPlayersWorldPos() const
{
    // get players viewpoint
    FVector PLayerViewPointLocation;
    FRotator PlayerViewPointRotation;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
        OUT PLayerViewPointLocation,
        OUT PlayerViewPointRotation);

    // draw a line from player showing the reach
    return PLayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}