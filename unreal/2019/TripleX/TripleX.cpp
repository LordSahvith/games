#include <iostream>
/*
 
 __          __  _                                    
 \ \        / / | |                                   
  \ \  /\  / /__| | ___ ___  _ __ ___   ___           
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \          
    \  /\  /  __/ | (_| (_) | | | | | |  __/          
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|            
                        | |          
                        | |_  __         
                        | __/ _ \                                     
  _____        __ _ _ _ | || (_) |  _   _             
 |_   _|      / _(_) | | \__\___/  | | (_)            
   | |  _ __ | |_ _| | |_ _ __ __ _| |_ _  ___  _ __  
   | | | '_ \|  _| | | __| '__/ _` | __| |/ _ \| '_ \ 
  _| |_| | | | | | | | |_| | | (_| | |_| | (_) | | | |
 |_____|_| |_|_| |_|_|\__|_|  \__,_|\__|_|\___/|_| |_|
                                                      
                                                      
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
  std::cout << "\n\n";
  std::cout << " _____        __ _ _ _             _   _             \n";
  std::cout << "|_   _|      / _(_) | |           | | (_)            \n";
  std::cout << "  | |  _ __ | |_ _| | |_ _ __ __ _| |_ _  ___  _ __  \n";
  std::cout << "  | | | '_ \\|  _| | | __| '__/ _` | __| |/ _ \\| '_ \\ \n";
  std::cout << " _| |_| | | | | | | | |_| | | (_| | |_| | (_) | | | |\n";
  std::cout << "|_____|_| |_|_| |_|_|\\__|_|  \\__,_|\\__|_|\\___/|_| |_|\n\n\n\n";
  std::cout << "You're a Wetboy Assassin hired by the Sa'kage.\n";
  std::cout << "They want you to rid the country of the insulent King.\n";
  std::cout << "Your task is simple...infiltrate the castle,\n";
  std::cout << "find the King unnoticed & kill him.\n\n";
}

void DoorCreate(int Level)
{
  if (Level < 4)
  {
    std::cout << " ____________\n";
    std::cout << "|  ________  |\n";
    std::cout << "| |        | |      ___    ___    ___\n";
    std::cout << "| |        | |     |   |  |   |  |   |\n";
    std::cout << "| |   " << Level << "  ()| |     | 1 |  | 2 |  | 3 |\n";
    std::cout << "| |        | |     |___|  |___|  |___|\n";
    std::cout << "| |        | |\n";
    std::cout << "| |________| |\n";
    std::cout << "|____________|\n\n";
  }
  else
  {
    std::cout << " ____________\n";
    std::cout << "|  ________  |\n";
    std::cout << "| |        | |      ___    ___    ___\n";
    std::cout << "| |        | |     |   |  |   |  |   |\n";
    std::cout << "| | /\\_/\\()| |     | 1 |  | 2 |  | 3 |\n";
    std::cout << "| | |___|  | |     |___|  |___|  |___|\n";
    std::cout << "| |        | |\n";
    std::cout << "| |________| |\n";
    std::cout << "|____________|\n\n";
  }
}

void Levels(int Level, int Codes)
{
  if (Level == 1)
  {
    std::cout << "The first door you come to has a level of " << Level << ".\n";
  }
  else if (Level == 4)
  {
    std::cout << "The King is just beyond this door.\n";
    std::cout << "Listen quietly and you can hear his unsuspecting snoring.\n";
    std::cout << "Once inside dispatch of him silently and quickly.\n\n";
  }
  else
  {
    std::cout << "This door has a level of " << Level << ".\n";
  }
  std::cout << "You must pick the lock by guessing the " << Codes << " codes...\n";
  DoorCreate(Level);
}

bool PlayGame(int Level, int NumberOfCodes)
{
  if (Level == 1)
  {
    Introduction();
  }

  Levels(Level, NumberOfCodes);

  // Declare the 3 number code
  const int CodeA = rand() % 10;
  const int CodeB = rand() % 10;
  const int CodeC = rand() % 10;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  // Print CodeSum & CodeProduct to the terminal
  std::cout << "The codes add-up to: " << CodeSum;
  std::cout << "\nThe codes multiply to give: " << CodeProduct;

  // Store player guess
  int GuessA, GuessB, GuessC;
  std::cout << "\n\nYou enter: ";
  std::cin >> GuessA >> GuessB >> GuessC;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  // Check if player's guess is correct
  if (GuessSum == CodeSum && GuessProduct == CodeProduct)
  {
    if (Level < 4)
    {
      std::cout << "\nWell done. You've successfully unlocked this door.\n\n";
    }
    else
    {
      std::cout << "\nWell done. You've successfully assassinated the King.\n\n";
    }
    return true;
  }
  else
  {
    std::cout << "\nKA'BOOOM! You were blown to pieces.\n\n";
    return false;
  }
}

int main()
{
  int LevelDifficulty = 1;
  int NumberOfCodes = 3;
  const int MaxDifficulty = 4;

  while (LevelDifficulty <= MaxDifficulty) // loop through game until last level
  {
    bool bLevelComplete = PlayGame(LevelDifficulty, NumberOfCodes);
    std::cin.clear();  // clears any errors
    std::cin.ignore(); // discards the buffer

    if (bLevelComplete)
    {
      ++LevelDifficulty;
    }
    else
    {
      LevelDifficulty = 1;
    }
  }

  return 0;
}