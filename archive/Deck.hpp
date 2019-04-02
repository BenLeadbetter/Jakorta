#ifndef GUARD__DECK_H
#define GUARD__DECK_H

#include <vector>
#include "Card.hpp"

typedef std::vector<Card*> Deck;

void shuffle(Deck&);


#endif