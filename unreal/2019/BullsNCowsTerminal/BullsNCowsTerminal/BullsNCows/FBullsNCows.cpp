#include "FBullsNCows.h"
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

// constructor
FBullCowGame::FBullCowGame() { Reset(); }

// getters
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
  if (!IsIsogram(Guess)) // if the guess isn't an isogram
  {
    return EGuessStatus::Not_Isogram; 
  }
  else if (false) // if the guess isn't all lowercase
  {
    return EGuessStatus::Not_Lowercase; // TODO write function
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
  bGameIsWon = false;
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

  if (BullCowCount.Bulls == WordLength)
  {
    bGameIsWon = true;
  }

  return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
  // treat 0 and 1 letter words as isograms
  if (Guess.length() <= 1)
  {
    return true;
  }

  TMap<char, bool> LetterSeen; // setup our map
  // loop through all the letters of the word
  for (auto Letter : Guess)
  {
    Letter = tolower(Letter);
    if (LetterSeen[Letter])
    {
      return false; // we do NOT have and isogram
    }
    else
    {
      LetterSeen[Letter] = true; // add the letter to the map as seen
    }
  }

  return true; // for example in cases where /0 is entered
}