#include "FBullsNCows.h"

using FString = std::string;
using int32 = int;

// constructor
FBullCowGame::FBullCowGame() { Reset(); }

// getters
int32 FBullCowGame::GetMaxTries() const {	return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

// Reset game
void FBullCowGame::Reset()
{
  constexpr int32 MAX_TRIES = 3;
  MyMaxTries = MAX_TRIES;

  MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
