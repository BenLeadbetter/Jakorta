//source file for the CharPool class from the GameBoard header file

#include "GameBoard.hpp"
#include <algorithm>
#include <iterator>


/*
****************************************
         methods for CharPool
****************************************
*/

CharPool::CharPool(const CharPool& charPool)
{
    m_Charactors = charPool.m_Charactors;
    m_playerIndex = charPool.m_playerIndex;
}

void CharPool::placeOnTop(Card* card)
{
    m_Charactors.push_back(card);
}

void CharPool::removeCard(Card* card)
{
    // identify the appropriate card to remove
    std::vector<Card*> tempCards;
    auto iter = std::find(m_Charactors.begin(), m_Charactors.end(), card);
    if(iter == m_Charactors.end())
        throw("Could not remove card. Card not found in PlayerHand.");
    
    // copy all but (one copy of) the removed card to tempCards
    copy(m_Charactors.begin(), iter, std::back_inserter(tempCards));
    copy(iter + 1, m_Charactors.end(), std::back_inserter(tempCards));

    // replace old hand
    m_Charactors = tempCards;
}

void CharPool::returnToDeck(std::vector<Card*> deck)
{
    while(m_Charactors.size() != 0)
    {
        deck.push_back(m_Charactors[m_Charactors.size() - 1]);
        m_Charactors.pop_back();
    }
}