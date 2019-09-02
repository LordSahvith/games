#include <iostream>
#include <string>

void PrintIntro();
std::string GetGuessAndPrintBack();

int main()
{
	PrintIntro();

	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 0; count < NUMBER_OF_TURNS; count++) {
		GetGuessAndPrintBack();
		std::cout << std::endl;
	}

	std::cout << std::endl;
	return 0;
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
std::string GetGuessAndPrintBack()
{
	std::string Guess = "";
	std::cout << "Enter guess: ";
	std::getline(std::cin, Guess);

	// repeat the guess back to them
	std::cout << "Your guess: " << Guess << std::endl;
	return Guess;
}