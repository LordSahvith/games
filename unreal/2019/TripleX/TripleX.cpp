#include <iostream>

int main()
{
  // Print welcome message to the terminal 
  std::cout << std::endl << "You are wetboy assassin hired by the Sa'kage to infiltrate the castle...";
  std::cout << std::endl;
  std::cout << "In order to enter the first door you must pick the lock..." << std::endl;

  // Declare the 3 number code
  const int CodeA = 4;
  const int CodeB = 3;
  const int CodeC = 2;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  // Print CodeSum & CodeProduct to the terminal
  std::cout << std::endl;
  std::cout << "There are 3 numbers in the code" << std::endl;
  std::cout << "The codes add-up to: " << CodeSum << std::endl;
  std::cout << "The codes multiply to give: " << CodeProduct << std::endl;

  int PlayerGuess;

  // End game
  return 0;
}