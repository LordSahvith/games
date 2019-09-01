// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Howdy Partner!"));
    PrintLine(TEXT("Guess the 6 letter word")); // Magic number remove!
    PrintLine(TEXT("Press enter to continue..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
  ClearScreen();
  FString HiddenWord = TEXT("naruto"); // move outside this function
  PrintLine(Input);

  if (Input == HiddenWord) {
    PrintLine(TEXT("Nice Job."));
  }
  else {
    PrintLine(TEXT("Maybe next time."));
  }
}