#include <iostream>
#include <string>
#include "FBullsNCows.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
  int MaxTries = BCGame.GetMaxTries();

  // loop for the number of turns asking for guesses
  for (int count = 0; count < MaxTries; count++)
  {
    std::string Guess = GetGuess();
    std::cout << "Your guess: " << Guess << std::endl << std::endl;
  }
  std::cout << std::endl;
}

// introduce the game
void PrintIntro()
{
  constexpr int WORD_LENGTH = 4;

  std::cout << "Welcome to Bulls N Cows!\n";
  std::cout << "Can you guess the " << WORD_LENGTH;
  std::cout << " letter isogram I'm thinking of?\n\n";
  return;
}

// get a guess from the player
std::string GetGuess()
{
  int CurrentTry = BCGame.GetCurrentTry();
  std::string Guess = "";
  std::cout << "Try " << CurrentTry << ". Enter guess: ";
  std::getline(std::cin, Guess);
  return Guess;
}

bool AskToPlayAgain()
{
  std::cout << "Do you want to play again (y/n)?";
  std::string Response = "";
  getline(std::cin, Response);
  return (Response[0] == 'y') || (Response[0] == 'Y');
}