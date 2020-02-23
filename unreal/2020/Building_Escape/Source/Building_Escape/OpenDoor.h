// Copyright 2020 Lord Sahvith

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
    void OpenDoor(float DeltaTime);
    void CloseDoor(float DeltaTime);
    float TotalMassOfActors() const;
    void FindAudioComponent();
    void FindPressurePlate();
    void SetupDoorOpenOptions();

    // tracks whether the sounds was played
    bool bOpenDoorSound = false;
    bool bCloseDoorSound = true;

private:
    float InitialYaw;
    float CurrentYaw;

    UPROPERTY(EditAnywhere)
    float MassToOpenDoors = 50.f;

    UPROPERTY(EditAnywhere)
    float OpenAngle = 90.f;

    float DoorLastOpened = 0.f;
    
    UPROPERTY(EditAnywhere)
    float DoorOpenSpeed = 1.2f;
    
    UPROPERTY(EditAnywhere)
    float DoorCloseSpeed = 2.f;

    UPROPERTY(EditAnywhere)
    float DoorCloseDelay = 0.5f;

    UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate = nullptr;
		
    UPROPERTY(EditAnywhere)
    AActor* ActorThatOpens = nullptr;

    UPROPERTY()
    UAudioComponent* AudioComponent = nullptr;
};
