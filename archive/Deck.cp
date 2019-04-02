// source file for the Deck header

#include "Deck.hpp"
#include <algorithm>

// definition for the shuffle function
void shuffle(Deck& deck)
{
    Deck::size_type deck_size = deck.size();
    Deck ret;

    while(ret.size() != deck_size)
    {
        // seed the random number generator
        srand((int)time(0) % deck.size());

        // push a random card to the back of ret
        ret.push_back(deck[rand()]);

        // delete that card from the deck
        
    }
}