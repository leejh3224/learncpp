// calculator
#include <iostream>

int getUserInput()
{
  std::cout << "please give me a number: ";
  int userInput;
  std::cin >> userInput;

  return userInput;
}

void calculate(int number, char op, int number2)
{
  using std::cout;

  switch (op)
  {
  case '+':
  {
    int result = number + number2;
    cout << number << " + " << number2 << " = " << result << "\n";
    break;
  }
  case '-':
  {
    int result = number - number2;
    cout << number << " - " << number2 << " = " << result << "\n";
    break;
  }
  case '*':
  {
    int result = number * number2;
    cout << number << " * " << number2 << " = " << result << "\n";
    break;
  }
  case '/':
  {
    int result = number / number2;
    cout << number << " / " << number2 << " = " << result << "\n";
    break;
  }
  default:
    cout << "Invalid operator! only +, -, *, / are allowed"
         << "\n";
    break;
  }
}

int main()
{
  int number = getUserInput();
  int number2 = getUserInput();

  std::cout << "what kind of operation do you want to execute?: ";
  char op;
  std::cin >> op;

  calculate(number, op, number2);

  return 0;
}

// print number of legs
#include <iostream>
#include <string>

enum class AnimalType
{
  PIG,
  CHICKEN,
  GOAT,
  CAT,
  DOG,
  OSTRICH,
};

struct Animal
{
  AnimalType type;
  short legs;
  std::string name;
};

std::string getAnimalName(Animal animal)
{
  switch (animal.type)
  {
  case AnimalType::CAT:
    return "cat";
  case AnimalType::CHICKEN:
    return "chicken";
  case AnimalType::DOG:
    return "dog";
  case AnimalType::GOAT:
    return "goat";
  case AnimalType::OSTRICH:
    return "ostrich";
  case AnimalType::PIG:
    return "pig";
  default:
    return "unknown";
  }
}

void printNumberOfLegs(Animal animal)
{
  using std::cout;

  cout << "A " << animal.name << " has " << animal.legs << " legs."
       << "\n";
}

int main()
{
  Animal Cat = {AnimalType::CAT, 4};
  Cat.name = getAnimalName(Cat);
  Animal Chicken = {AnimalType::CHICKEN, 2};
  Chicken.name = getAnimalName(Chicken);

  printNumberOfLegs(Cat);
  printNumberOfLegs(Chicken);

  return 0;
}