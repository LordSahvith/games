#include <iostream>
/*
  _____        __ _ _ _             _   _             
 |_   _|      / _(_) | |           | | (_)            
   | |  _ __ | |_ _| | |_ _ __ __ _| |_ _  ___  _ __  
   | | | '_ \|  _| | | __| '__/ _` | __| |/ _ \| '_ \ 
  _| |_| | | | | | | | |_| | | (_| | |_| | (_) | | | |
 |_____|_| |_|_| |_|_|\__|_|  \__,_|\__|_|\___/|_| |_|
         
*/

void Introduction() 
{
  // Print welcome message to the terminal 
  std::cout << " _____        __ _ _ _             _   _             \n";
  std::cout << "|_   _|      / _(_) | |           | | (_)            \n";
  std::cout << "  | |  _ __ | |_ _| | |_ _ __ __ _| |_ _  ___  _ __  \n";
  std::cout << "  | | | '_ \\|  _| | | __| '__/ _` | __| |/ _ \\| '_ \\ \n";
  std::cout << " _| |_| | | | | | | | |_| | | (_| | |_| | (_) | | | |\n";
  std::cout << "|_____|_| |_|_| |_|_|\\__|_|  \\__,_|\\__|_|\\___/|_| |_|\n";
  std::cout << std::endl << "You are wetboy assassin hired by the Sa'kage to infiltrate the castle...\n";
  std::cout << "In order to enter the first door you must pick the lock by guessing the 3 numbers...\n\n";
}

void PlayGame()
{
  Introduction();

  // Declare the 3 number code
  const int CodeA = 4;
  const int CodeB = 3;
  const int CodeC = 2;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  // Print CodeSum & CodeProduct to the terminal
  std::cout << "There are 3 numbers in the code\n";
  std::cout << "The codes add-up to: " << CodeSum;
  std::cout << "\nThe codes multiply to give: " << CodeProduct;

  // Store player guess 
  int GuessA, GuessB, GuessC;
  std::cout << "\n\nEnter guess: ";
  std::cin >> GuessA >> GuessB >> GuessC;
 
  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  // Check if player's guess is correct
  if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
  {
    std::cout << "\nYou win!\n";
  } 
  else 
  {
    std::cout << "\nKA'BOOOM! You were blown to pieces.\n";
  }
}

int main()
{
  PlayGame();
  
  return 0;
}