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
FText GetValidGuess();
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

// introduce the game
void PrintIntro()
{
  std::cout << "\nWelcome to Bulls N Cows!\n";
  std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
  std::cout << " letter isogram I'm thinking of?\n";
  return;
}

void PlayGame()
{
  BCGame.Reset();
  int32 MaxTries = BCGame.GetMaxTries();

  // loop asking for guesses while the game is NOT won
  // and there are still tries remaining
  for (int32 count = 0; count < MaxTries; count++) // TODO change from FOR to WHILE
  {
    FText Guess = GetValidGuess();

    // submit valid guess to the game, and receive counts
    FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

    std::cout << "Bulls = " << BullCowCount.Bulls;
    std::cout << "  Cows = " << BullCowCount.Cows << std::endl;
  }

  // TODO summarize game
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
  FText Guess = "";
  EGuessStatus Status = EGuessStatus::Invalid_Status;
  do
  {
    // get guess from player
    int32 CurrentTry = BCGame.GetCurrentTry();
    std::cout << "\nTry " << CurrentTry << ". Enter guess: ";
    std::getline(std::cin, Guess);

    Status = BCGame.CheckGuessValidity(Guess);
    switch (Status)
    {
    case EGuessStatus::Wrong_Length:
      std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.";
      break;
    case EGuessStatus::Not_Isogram:
      std::cout << "Please enter a word without repeating any letters.";
      break;
    case EGuessStatus::Not_Lowercase:
      std::cout << "Please enter all lowercase letters.";
      break;
    default:
      // assume guess is valid
      break;
    }
    std::cout << std::endl;
  } while (Status != EGuessStatus::OK); // keep looping until we get no errors
  return Guess;
}

bool AskToPlayAgain()
{
  std::cout << "Do you want to play again (y/n)?";
  FText Response = "";
  getline(std::cin, Response);
  return (Response[0] == 'y') || (Response[0] == 'Y');
}