//source file for the CardInHand class from the GameBoard header file

#include "GameBoard.hpp"
#include <algorithm>
#include <iterator>


/*
****************************************
         methods for CardInHand
****************************************
*/

void CardInHand::addCard(Card* card)
{
    // store a pointer to the original card
    // and change card's state to IN_TRANSIT
    m_Card = card;
    m_Card->m_InTransit = true;
    
}

void CardInHand::removeCard()
{
    m_Card->m_InTransit = false;
    m_Card = 0;
}

void CardInHand::draw(sf::RenderWindow& window, sf::Vector2i position)
{
    if(m_Card)
    {
        sf::Sprite cardSprite = m_Card->getSprite();
        cardSprite.setOrigin(sf::Vector2f(72, 104));
        cardSprite.setPosition(sf::Vector2f(position.x, position.y));
        window.draw(cardSprite);
    }
}