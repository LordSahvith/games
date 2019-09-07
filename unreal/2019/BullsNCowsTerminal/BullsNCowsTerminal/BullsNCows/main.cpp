/* 
  This is the conosole executable, that makes use of the BullCow class
  This acts as teh view in a MVC pattern, and is responsible for all
  user interatction. For game logic see the FBullCowGame class.
*/
#include <iostream>
#include <string>
#include "FBullsNCows.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

int main()
{
  do
  {
    PrintIntro();
    PlayGame();
  } while (AskToPlayAgain());

  return 0; // exit application
}

void PlayGame()
{
  BCGame.Reset();
  int32 MaxTries = BCGame.GetMaxTries();

  // loop for the number of turns asking for guesses
  // TODO change from FOR to WHILE loop once we are validation tries
  for (int32 count = 0; count < MaxTries; count++)  {
    FText Guess = GetGuess(); // TODO make loop checking valid

    // submit valid guess to the game, and receive counts
    FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
    // print number of bulls and cows
    std::cout << "Bulls = " << BullCowCount.Bulls;
    std::cout << "  Cows = " << BullCowCount.Cows << std::endl;
  }

  // TODO summarize game
}

// introduce the game
void PrintIntro()
{
  constexpr int32 WORD_LENGTH = 4;

  std::cout << "\nWelcome to Bulls N Cows!\n";
  std::cout << "Can you guess the " << WORD_LENGTH;
  std::cout << " letter isogram I'm thinking of?\n";
  return;
}

// get a guess from the player
FText GetGuess()
{
  int32 CurrentTry = BCGame.GetCurrentTry();
  FText Guess = "";
  std::cout << "\nTry " << CurrentTry << ". Enter guess: ";
  std::getline(std::cin, Guess);
  return Guess;
}

bool AskToPlayAgain()
{
  std::cout << "Do you want to play again (y/n)?";
  FText Response = "";
  getline(std::cin, Response);
  return (Response[0] == 'y') || (Response[0] == 'Y');
}