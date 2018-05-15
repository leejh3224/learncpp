#include <string>
#include <iostream>

class Monster
{
public:
  enum MonsterType
  {
    DRAGON,
    GOBLIN,
    ORGE,
    ORC,
    SKELE,
    MAX_MONSTER_TYPES,
  };

private:
  MonsterType m_type;
  std::string m_name;
  std::string m_roar;
  int m_hitPoints;

public:
  Monster(MonsterType type = DRAGON, std::string name = "Dragon", std::string roar = "Rwww", int hitPoints = 8)
      : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
  {
  }

  std::string getTypeString() const
  {
    switch (m_type)
    {
    case DRAGON:
      return "dragon";
    case GOBLIN:
      return "goblin";
    case ORGE:
      return "orge";
    case ORC:
      return "orc";
    case SKELE:
      return "skele";
    default:
      return "unknown";
    }
  }

  void print() const
  {
    std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << "\n";
  }
};

class MonsterGenerator
{
public:
  static int getRandomNumber(int min, int max)
  {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
  }

  static Monster generateMonster()
  {
    // you can convert random int to MonsterType like this!
    Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
    int hitPoints = getRandomNumber(1, 100);

    const int randomIndex = getRandomNumber(0, 5);
    static std::string s_names[6]{"Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans"};
    static std::string s_roars[6]{"*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};

    return Monster(type, s_names[randomIndex], s_roars[randomIndex], hitPoints);
  }
};

int main()
{
  srand(static_cast<unsigned int>(time(0)));
  rand();

  Monster m = MonsterGenerator::generateMonster();
  m.print();

  return 0;
}