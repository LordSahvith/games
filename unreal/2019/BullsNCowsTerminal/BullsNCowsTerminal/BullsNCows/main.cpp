#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
void PrintGuess(std::string);

int main()
{
	PrintIntro();
	PlayGame();
	return 0; // exit application
}

void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 0; count < NUMBER_OF_TURNS; count++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess: " << Guess << std::endl << std::endl;
	}
	std::cout << std::endl;
}

// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls N Cows!\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n\n";
	return;
}

// get a guess from the player
std::string GetGuess()
{
	std::string Guess = "";
	std::cout << "Enter guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}