#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
  FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO  make a more rich return value
	bool CheckGuessValidity(FString); // TODO make a more rich return value

private:
  // see contructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
  // provide a method for counting bulls and cows, and increading turn #
};