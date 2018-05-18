#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
protected:
  std::string m_name;
  char m_symbol;
  int m_health;
  int m_damage;
  int m_gold;

public:
  Creature(std::string name, char symbol, int health, int damage, int gold)
      : m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage}, m_gold{gold}
  {
  }

  const std::string &getName() const { return m_name; }
  char getSymbol() const { return m_symbol; }
  int getHealth() const { return m_health; }
  int getDamage() const { return m_damage; }
  int getGold() const { return m_gold; }

  void reduceHealth(int point)
  {
    m_health -= point;
  }

  bool isDead() const
  {
    return m_health <= 0;
  }

  void addGold(int gold)
  {
    m_gold += gold;
  }
};

class Player : public Creature
{
protected:
  int m_level = 1;

public:
  Player(std::string name)
      : Creature{name, '@', 10, 1, 0}
  {
  }

  int getLevel() const { return m_level; }
  bool hasWon() const { return m_level >= 20; }

  void levelUp()
  {
    m_level += 1;
    m_damage += 1;
  }
};

class Monster : public Creature
{
public:
  enum Type
  {
    DRAGON,
    ORC,
    SLIME,
    MAX_TYPES,
  };

  struct MonsterData
  {
    const char *name;
    char symbol;
    int health;
    int damage;
    int gold;
  };

  static MonsterData monsterData[MAX_TYPES];

  Monster(Type type)
      : Creature(
            monsterData[type].name,
            monsterData[type].symbol,
            monsterData[type].health,
            monsterData[type].damage,
            monsterData[type].gold)
  {
  }

  static Monster getRandomMonster()
  {
    int num = getRandomNumber(0, MAX_TYPES - 1);
    return Monster(static_cast<Type>(num));
  }
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]{
    {"dragon", 'D', 20, 4, 100},
    {"orc", 'o', 4, 2, 25},
    {"slime", 's', 1, 1, 10}};

void attackMonster(Player &p, Monster &m)
{
  if (p.isDead())
    return;

  const int damage = p.getDamage();
  const int level = p.getLevel();
  const int gold = m.getGold();
  const std::string monster = m.getName();

  std::cout << "You hit " << monster << " for " << damage << " damage.\n";

  m.reduceHealth(damage);

  if (m.isDead())
  {
    std::cout << "You killed the " << monster << "\n.";
    p.levelUp();
    std::cout << "You are now level " << level << " level. \n";
    std::cout << "You got " << gold << "gold. \n";
    p.addGold(gold);
  }
}

void attackPlayer(Monster &m, Player &p)
{
  if (m.isDead())
    return;

  p.reduceHealth(m.getDamage());
  std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}

void fightMonster(Player &p)
{
  // First randomly generate a monster
  Monster m = Monster::getRandomMonster();
  std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";

  while (!m.isDead() && !p.isDead())
  {
    std::cout << "(R)un or (F)ight: ";
    char input;
    std::cin >> input;
    if (input == 'R' || input == 'r')
    {
      // 50% chance of fleeing successfully
      if (getRandomNumber(1, 2) == 1)
      {
        std::cout << "You successfully fled.\n";
        return; // success ends the encounter
      }
      else
      {
        std::cout << "You failed to flee.\n";
        attackPlayer(m, p);
        continue;
      }
    }

    if (input == 'F' || input == 'f')
    {
      attackMonster(p, m);
      attackPlayer(m, p);
    }
  }
}

int main()
{
  srand(static_cast<unsigned int>(time(0)));
  rand();

  std::cout << "Enter your name: ";
  std::string playerName;
  std::cin >> playerName;

  Player p(playerName);
  std::cout << "Welcome, " << p.getName() << '\n';

  // If the player isn't dead and hasn't won yet, the game continues
  while (!p.isDead() && !p.hasWon())
    fightMonster(p);

  // At this point, the player is either dead or has won
  if (p.isDead())
  {
    std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
    std::cout << "Too bad you can't take it with you!\n";
  }
  else
  {
    std::cout << "You won the game with " << p.getGold() << " gold!\n";
  }

  return 0;
}