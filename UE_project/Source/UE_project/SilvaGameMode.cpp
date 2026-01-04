// Fill out your copyright notice in the Description page of Project Settings.

#include "SilvaGameMode.h"

void ASilvaGameMode::StartPlay()
{
    Super::StartPlay();

    // Ensures the game is running properly
    check (GEngine != nullptr);

    // Prints Log message on screen

    // GEngine : global POINTER to a UEngine class instance
    // AddOnScreenDebugMessage : function of the UEngine class
    // '->' : pointer dereference operator; used to access members through a pointer
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Hello World!"));

    // Prints Log message in logs
    UE_LOG(LogTemp, Warning, TEXT("Hello World!"));
}