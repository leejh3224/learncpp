#ifndef DECK_H
#define DECK_H

#include <array>

class Deck
{
private:
  std::array<Card, 52> m_deck;
  int m_cardIndex = 0;

public:
  Deck();
  void printDeck() const;
  void shuffleDeck();
  const Card &dealCard();

private:
  static int getRandomNumber(int min, int max)
  {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
  }

  static void swapCard(Card &a, Card &b)
  {
    Card temp = a;
    a = b;
    b = temp;
  }
};

#endif