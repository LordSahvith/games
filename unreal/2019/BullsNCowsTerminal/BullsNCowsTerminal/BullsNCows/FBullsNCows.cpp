#include "FBullsNCows.h"

using FString = std::string;
using int32 = int;

// constructor
FBullCowGame::FBullCowGame() { Reset(); }

// getters
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const
{
  return false;
}

// Reset game
void FBullCowGame::Reset()
{
  constexpr int32 MAX_TRIES = 3;
  MyMaxTries = MAX_TRIES;

  const FString HIDDEN_WORD = "ant";
  MyHiddenWord = HIDDEN_WORD;
  MyCurrentTry = 1;
  return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
  return false;
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
  // increment the turn number
  MyCurrentTry++;

  // setup a return variable
  FBullCowCount BullCowCount;

  // loop through all letter in the guess
  int32 HiddenWordLength = MyHiddenWord.length();
  for (int32 i = 0; i < HiddenWordLength; i++)
  {
    // compare letters against the hidden word
    for (int32 j = 0; j < HiddenWordLength; j++)
    {
      // if they match
      if (Guess[i] == MyHiddenWord[i])
      {
        if (i == j) // if they're in the same place
        {
          BullCowCount.Bulls++; // increment bulls
        }
        else
        {
          BullCowCount.Cows++; // increment cows
        }
      }
    }
  }

  return BullCowCount;
}
