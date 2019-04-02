//source file for the Discards class from the GameBoard header file

#include "GameBoard.hpp"
#include <algorithm>
#include <iterator>



/*
****************************************
         methods for Discards
****************************************
*/

void Discards::placeOnTop(Card* card)
{
    card->orient(CardState::FACE_UP);
    m_Cards.push_back(card);
}

Card* Discards::topCard()
{
    return m_Cards[m_Cards.size() - 1];
}

void Discards::returnToDeck(std::vector<Card*> deck)
{
    while(m_Cards.size() != 0)
    {
        Card* card = m_Cards[m_Cards.size() - 1];
        card->orient(CardState::FACE_DOWN);
        deck.push_back(card);
        m_Cards.pop_back();
    }
}
