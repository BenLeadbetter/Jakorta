// source file for the RolePool class in the GameBoard.hpp header

#include "GameBoard.hpp"

void RolePool::placeOnTop(Card* card)
{
    card->orient(CardState::FACE_UP);
    m_Cards.push_back(card);
}

void RolePool::setSprites(sf::Vector2f position)
{
    // set the sprites for each card
    for(std::vector<Card*>::size_type i = 0; i != m_Cards.size(); ++i)
    {

        m_Cards[i]->getSprite().scale(sf::Vector2f(m_CardScale, m_CardScale));
        m_Cards[i]->getSprite().setPosition(position + sf::Vector2f(255 * i, 0));
    }
}

void RolePool::draw(sf::RenderWindow& window)
{
    // draw all six cards in the pool
    for(std::vector<Card*>::size_type i = 0; i != m_Cards.size(); ++i)
    {
        // draw the highlight, if any
        if(m_Cards[i]->m_Highlighted)
        {
            sf::RectangleShape highlight;
            highlight.setFillColor(sf::Color::Yellow);
            highlight.setSize(
                sf::Vector2f(
                        30 + m_Cards[i]->getSprite().getGlobalBounds().width,
                        30 + m_Cards[i]->getSprite().getGlobalBounds().height
                ));
            highlight.setPosition(m_Cards[i]->getSprite().getPosition() + sf::Vector2f(-15.0f, -15.0f));
            window.draw(highlight);
        }

        // draw the card
        window.draw(m_Cards[i]->getSprite());
    }
}

void RolePool::highlight(sf::Vector2i mousePosition)
{
    // check each card to see if the mouse is over it
    for(std::vector<Card*>::size_type i = 0; i != m_Cards.size(); ++i)
    {        
        // Check the sprite for intersections
        for (std::vector<Card*>::size_type i = 0; i != m_Cards.size(); ++i)
        {
            if(m_Cards[i]->getSprite().getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y)))
            {
                m_Cards[i]->m_Highlighted = true;

            } else {

                m_Cards[i]->m_Highlighted = false;

            }
        }
    }
}