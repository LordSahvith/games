#include <iostream>


int main()
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls N Cows!\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n\n";

	// get a guess from the player
	std::string Guess = "";
	std::cout << "Enter guess: ";
	std::cin >> Guess;

	// repeat the guess back to them
	std::cout << "Your guess: " << Guess;


	std::cout << std::endl;
	return 0;
}