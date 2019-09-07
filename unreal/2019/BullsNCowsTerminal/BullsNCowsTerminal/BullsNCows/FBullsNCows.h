#pragma once
#include <string>

class FBullCowGame {
public:
  FBullCowGame(); // constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO  make a more rich return value
	bool CheckGuessValidity(std::string);

private:
  // see contructor for initialization
	int MyCurrentTry;
	int MyMaxTries;
};