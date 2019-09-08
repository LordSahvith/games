#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values intialized to 0
struct FBullCowCount
{
  int32 Bulls = 0;
  int32 Cows = 0;
};

enum class EGuessStatus
{
  Invalid_Status,
  OK, 
  Not_Isogram,
  Wrong_Length,
  Not_Lowercase
};

class FBullCowGame
{
public:
  FBullCowGame(); // constructor

  // getters
  int32 GetMaxTries() const;
  int32 GetCurrentTry() const;
  int32 GetHiddenWordLength() const;

  bool IsGameWon() const;
  EGuessStatus CheckGuessValidity(FString) const; // TODO make a more rich return value

  void Reset(); // TODO  make a more rich return value
  FBullCowCount SubmitValidGuess(FString);

private:
  // see contructor for initialization
  int32 MyCurrentTry;
  int32 MyMaxTries;
  FString MyHiddenWord;
};