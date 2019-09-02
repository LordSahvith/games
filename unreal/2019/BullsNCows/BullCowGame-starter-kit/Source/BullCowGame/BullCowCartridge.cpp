// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    // welcoming player 
    Super::BeginPlay();
    PrintLine(TEXT("Howdy Partner!"));
    PrintLine(TEXT("Guess the 6 letter word")); // Magic number remove!
    PrintLine(TEXT("Press enter to continue..."));

    // setup game
    HiddenWord = TEXT("naruto"); // get isogram
    // set lives

    // prompt player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
  ClearScreen();

  // checking PlayerGuessd

  PrintLine(Input);

  if (Input == HiddenWord) {
    PrintLine(TEXT("Nice Job."));
  }
  else {
    PrintLine(TEXT("Maybe next time."));
  }

  // check if isogram
  // prompt to guess again
  // check right number of characters
  // prompt to guess again

  // remove life

  // check if lives > 0
  // if yes GuessAgain
  // Show lives left
  // if no show GameOver & HiddenWord
  // Prompt to Play Again, press enter to play again? 
  // check user input
  // PlayAgain or quit
}