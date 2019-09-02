#include <iostream>


int main()
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls N Cows!\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	return 0;
}