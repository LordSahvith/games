#include "FBullsNCows.h"

// constructor
FBullCowGame::FBullCowGame() { Reset(); }

// getters
int FBullCowGame::GetMaxTries() const {	return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

// Reset game
void FBullCowGame::Reset()
{
  constexpr int MAX_TRIES = 3;
  MyMaxTries = MAX_TRIES;
  
  MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}
