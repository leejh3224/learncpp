// question #2-a
// failed to get correct answer
#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool playGame(int guesses, int number)
{
  for (int count = 1; count <= guesses; count++)
  {
    std::cout << "Guess #" << count << ": ";
    int guess;
    std::cin >> guess;

    if (guess > number)
      std::cout << "Your guess is too high \n";
    else if (guess < number)
      std::cout << "Your guess is too low \n";
    else
      return true
  }

  return false;
}

bool playAgain()
{
  char ch;
  do
  {
    std::cout << "Would you like to play again (y/n)? ";
    std::cin >> ch;
  } while (ch != 'y' && ch != 'n');

  return (ch == 'y');
}

int main()
{
  srand(static_cast<u_int>(time(0)));
  rand();

  const int guesses = 7;

  do
  {
    int number = getRandomNumber(1, 100);

    std::cout << "Let's play a game.  I'm thinking of a number.  You have " << guesses << " tries to guess what it is.\n";

    bool won = playGame(guesses, number);

    if (won)
      std::cout << "Correct! You win! \n";
    else
      std::cout << "Sorry, you lose. The correct number was " << number << "\n";
  } while (playAgain());

  std::cout << "Thank you for playing! \n";

  return 0;
}

// with input check
#include <iostream>
#include <cstdlib> // for srand() and rand()
#include <ctime>   // for time()

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // static used for efficiency, so we only calculate this value once
                                                                              // evenly distribute the random number across our range
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int getGuess(int count)
{
  while (1) // loop until user enters valid input
  {
    std::cout << "Guess #" << count << ": ";
    int guess;
    std::cin >> guess;

    if (std::cin.fail()) // has a previous extraction failed?
    {
      // yep, so let's handle the failure
      std::cin.clear();             // put us back in 'normal' operation mode
      std::cin.ignore(32767, '\n'); // and remove the bad input
    }
    else
    {
      std::cin.ignore(32767, '\n'); // remove any extraneous input
      return guess;
    }
  }
}

// returns true if the user won, false if they lost
bool playGame(int guesses, int number)
{
  // Loop through all of the guesses
  for (int count = 1; count <= guesses; ++count)
  {

    int guess = getGuess(count);

    if (guess > number)
      std::cout << "Your guess is too high.\n";
    else if (guess < number)
      std::cout << "Your guess is too low.\n";
    else // guess == number
      return true;
  }

  return false;
}

bool playAgain()
{
  // Keep asking the user if they want to play again until they pick y or n.
  char ch;
  do
  {
    std::cout << "Would you like to play again (y/n)? ";
    std::cin >> ch;
  } while (ch != 'y' && ch != 'n');

  return (ch == 'y');
}

int main()
{
  srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
  rand();                                    // discard the first result because rand() doesn't randomize the first random number very well in Visual Studio

  const int guesses = 7; // the user has this many guesses

  do // while the user still wants to play
  {
    int number = getRandomNumber(1, 100); // this is the number the user needs to guess

    std::cout << "Let's play a game.  I'm thinking of a number.  You have " << guesses << " tries to guess what it is.\n";

    bool won = playGame(guesses, number);
    if (won)
      std::cout << "Correct!  You win!\n";
    else
      std::cout << "Sorry, you lose.  The correct number was " << number << "\n";

  } while (playAgain());

  std::cout << "Thank you for playing.\n";
  return 0;
}