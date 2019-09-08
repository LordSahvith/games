#include "FBullsNCows.h"

using FString = std::string;
using int32 = int;

// constructor
FBullCowGame::FBullCowGame() { Reset(); }

// getters
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return false; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const 
{ 
  if (false) // if the guess isn't an isogram
  {
    return EGuessStatus::Not_Isogram;
  }
  else if (false) // if the guess isn't all lowercase
  {
    return EGuessStatus::Not_Lowercase;
  }
  else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
  {
    return EGuessStatus::Wrong_Length;
  }
  else // otherwise
  {
    return EGuessStatus::OK;
  }
}

// Reset game
void FBullCowGame::Reset()
{
  constexpr int32 MAX_TRIES = 5;
  const FString HIDDEN_WORD = "planet";

  MyMaxTries = MAX_TRIES;
  MyHiddenWord = HIDDEN_WORD;
  MyCurrentTry = 1;
  return;
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
  MyCurrentTry++;

  // setup a return variable
  FBullCowCount BullCowCount;
  int32 WordLength = MyHiddenWord.length(); // assuming same length as guess

  // loop through all letter in the hidden word
  for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
  {
    // compare letters against the hidden word
    for (int32 GChar = 0; GChar < WordLength; GChar++)
    {
      // if they match
      if (Guess[GChar] == MyHiddenWord[MHWChar])
      {
        if (MHWChar == GChar) // if they're in the same place
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