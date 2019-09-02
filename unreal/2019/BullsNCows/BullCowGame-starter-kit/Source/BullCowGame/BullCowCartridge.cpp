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
      --Lives;
      PrintLine(TEXT("Life lost!"));
      PrintLine(TEXT("You have %i lives left."), Lives);
      if (Lives > 0)
      {
        if (Input.Len() != HiddenWord.Len())
        {
          PrintLine(TEXT("Word is %i letters long, try again."), HiddenWord.Len());
        }
        else
        {
          PrintLine(TEXT("Try again."));
        }
      }
      else
      {
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
  Lives = HiddenWord.Len();
  bGameOver = false;

  PrintLine(TEXT("Guess the %i letter isogram."), HiddenWord.Len());
  PrintLine(TEXT("You have %i lives."), Lives);
  PrintLine(TEXT("Type in your guess...")); // prompt player for guess
}

void UBullCowCartridge::EndGame()
{
  bGameOver = true;
  PrintLine(TEXT("Press enter to play again."));
}