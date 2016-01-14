// Fill out your copyright notice in the Description page of Project Settings.

#include "QuickStart.h"
#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
   PrimaryActorTick.bCanEverTick = true;

   Magnitude = 20.0f;
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
   Super::BeginPlay();
   
}

// Called every frame
void AFloatingActor::Tick( float DeltaTime )
{
   Super::Tick( DeltaTime );

   // Add random coeff between 0.6 and 1.6
   float Coeff = rand();
   Coeff /= RAND_MAX;
   Coeff += 0.6;
   DeltaTime *= Coeff;

   FVector NewLocation = GetActorLocation();
   float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
   NewLocation.Z += DeltaHeight * Magnitude;       //Scale our height by a factor
   RunningTime += DeltaTime;

   // Add periodic motion on the X and Y axis
   int RunningTimeInt = static_cast<int>(RunningTime);
   if ((RunningTimeInt % 2) == 0)
   {
      NewLocation.X += 1;
      NewLocation.Y += 1;
   }
   else
   {
      NewLocation.X -= 1;
      NewLocation.Y -= 1;
   }

   SetActorLocation(NewLocation);
}

