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

  // Get player guess & print it to the terminal
  int GuessA, GuessB, GuessC;
  std::cout << std::endl << "Enter guess (a b c): ";
  std::cin >> GuessA;
  std::cin >> GuessB;
  std::cin >> GuessC;
  std::cout << "You entered: " << GuessA << " " << GuessB << " " << GuessC << std::endl;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  // std::cout << "Your guess adds up to: " << GuessSum << std::endl;
  // std::cout << "Your guess multiplies to: " << GuessProduct << std::endl;

  if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
  {
    std::cout << "You win!" << std::endl;
  } else {
    std::cout << "KA'BOOOM! You were blown to pieces." << std::endl;
  }

  // End game
  return 0;
}