//source file for the MainDeck class from the GameBoard header file

#include "GameBoard.hpp"
#include <algorithm>
#include <iterator>


/*
****************************************
         methods for MainDeck
****************************************
*/

// copy constructor
MainDeck::MainDeck(const MainDeck& mainDeck)
{
    // copy card pointers
    m_Deck = mainDeck.m_Deck;

    // copy back texture pointer
    mp_backTexture = mainDeck.mp_backTexture;
}

void MainDeck::placeOnTop(Card* card)
{
    card->orient(CardState::FACE_DOWN);
    card->getSprite().scale(sf::Vector2f(m_CardScale, m_CardScale));
    m_Deck.push_back(card);
}

void MainDeck::placeOnBottom(Card* card)
{
    // push the card onto a temporary deck
    std::vector<Card*> tempDeck;
    card->orient(CardState::FACE_DOWN);
    tempDeck.push_back(card);

    // copy the rest of the cards
    copy(m_Deck.begin(), m_Deck.end(), std::back_inserter(tempDeck));

    // reasign member deck
    m_Deck = tempDeck;
}

Card* MainDeck::removeTopCard()
{
    Card* ret =  m_Deck[m_Deck.size() - 1];
    m_Deck.pop_back();
    return ret;
}

Card* MainDeck::returnTopCard()
{
    return m_Deck[m_Deck.size() - 1];
}

void MainDeck::shuffle()
{
    std::vector<Card*> shuffledDeck;
    int i = 0;

    while(m_Deck.size() != 0)
    {
        // choose a random card index
        srand((int)time(0) + i);
        std::vector<Card*>::size_type cardIndex = rand() % m_Deck.size();

        // add this card to ret and remove from m_Deck
        shuffledDeck.push_back(m_Deck[cardIndex]);
        m_Deck.erase(m_Deck.begin() + cardIndex);

        ++i;
    }

    // reasign m_Deck
    m_Deck = shuffledDeck;
}

void MainDeck::highlight(sf::Vector2i mousePosition)
{

}

void MainDeck::draw(sf::RenderWindow& window, sf::Vector2f position)
{
    // draw the main deck if there are cards in it
    if(m_Deck.size() != 0)
    {
        // draw the top card
        returnTopCard()->getSprite().setPosition(position);
        window.draw(returnTopCard()->getSprite());

    }
}