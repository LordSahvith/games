// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
  // welcoming player
  Super::BeginPlay();

  SetupGame(); // setup game

  PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord); // Debug line
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
  /* 
  else 
 */

  if (bGameOver)
  {
    ClearScreen();
    SetupGame();
  }
  else // check PlayerGuess
  {
    if (Input == HiddenWord)
    {
      PrintLine(TEXT("You Won!"));
      EndGame();
    }
    else
    {
      if (Input.Len() != HiddenWord.Len())
      {
        PrintLine(TEXT("Word is %i letters long, you lost."), HiddenWord.Len());
        EndGame();
      }
      else
      {
        PrintLine(TEXT("You lost."));
        EndGame();
      }
    }
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

void UBullCowCartridge::SetupGame()
{
  // Welcome Player
  PrintLine(TEXT("Howdy Partner!"));

  HiddenWord = TEXT("force");
  Lives = 4;
  bGameOver = false;

  PrintLine(TEXT("Guess the %i letter isogram."), HiddenWord.Len());
  PrintLine(TEXT("Type in your guess...")); // prompt player for guess
}

void UBullCowCartridge::EndGame()
{
  bGameOver = true;
  PrintLine(TEXT("Press enter to play again."));
}