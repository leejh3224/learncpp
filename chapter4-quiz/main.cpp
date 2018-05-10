#include <iostream>
#include <string>

enum class MonsterType
{
  ORGE,
  DRAGON,
  ORC,
  GIANT_SPIDER,
  SLIME,
};

struct Monster
{
  MonsterType type;
  std::string name;
  int health;
};

std::string getMonsterType(Monster monster)
{
  if (monster.type == MonsterType::ORGE)
    return "Orge";
  else if (monster.type == MonsterType::SLIME)
    return "Slime";
  return "???";
}

void printMonster(Monster monster)
{
  using std::cout;
  std::string type = getMonsterType(monster);
  cout << "This " << type << " is named " << monster.name << " and has " << monster.health << " health \n";
}

int main()
{
  Monster Torg = {MonsterType::ORGE, "Torg", 145};
  Monster Blurp = {MonsterType::SLIME, "Blurp", 23};

  printMonster(Torg);
  printMonster(Blurp);

  return 0;
}