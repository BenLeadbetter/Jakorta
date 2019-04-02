// source file for the PlayerRole class from the GameBoard.hpp header

#include "GameBoard.hpp"

void PlayerRole::addCard(Card* card)
{
    m_Card = card;
}

void PlayerRole::draw(sf::RenderWindow& window, sf::Vector2f position)
{
    // draw the card in the specified position
    sf::Sprite cardSprite = m_Card->getSprite();
    cardSprite.setPosition(position);
    window.draw(cardSprite);
}