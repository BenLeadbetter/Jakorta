//source file for the PlayerHand class from the GameBoard header file

#include "GameBoard.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>

/*
****************************************
         methods for PlayerHand
****************************************
*/
void PlayerHand::placeOnTop(Card* card)
{
    card->orient(CardState::FACE_UP);
    m_Cards.push_back(card);
}

void PlayerHand::removeCard(Card* card)
{   
    // identify the appropriate card to remove
    std::vector<Card*> tempCards;
    auto iter = std::find(m_Cards.begin(), m_Cards.end(), card);
    if(iter == m_Cards.end())
        throw("Could not remove card. Card not found in PlayerHand.");
    
    // copy all but (one copy of) the removed card to tempCards
    copy(m_Cards.begin(), iter, std::back_inserter(tempCards));
    copy(iter + 1, m_Cards.end(), std::back_inserter(tempCards));

    // replace old hand
    m_Cards = tempCards;
}

void PlayerHand::returnToDeck(std::vector<Card*> deck)
{
    while(m_Cards.size() != 0)
    {
        deck.push_back(m_Cards[m_Cards.size() - 1]);
        m_Cards.pop_back();
    }
}

Card* PlayerHand::randomCard()
{
    // check hand has cards
    if(numberOfCards() == 0)
        throw("No cards in hand");
    
    // generate random card index
    srand((int)time(0));
    std::vector<Card*>::size_type cardIndex = rand() % numberOfCards();

    // return random card pointer
    return m_Cards[cardIndex];

}

std::vector<Card*>::size_type PlayerHand::numberOfCards() const
{
    return m_Cards.size();
}

void PlayerHand::draw(sf::RenderWindow& window, sf::Vector2f position, ResourceManager& resourceManager)
{
    //m_Cards[0]->getSprite().setTexture(resourceManager.getTexture("sifter"));
    
    window.draw(m_Cards[0]->getSprite());

    /*
    // draw a rectangle background
    sf::RectangleShape backRect;
    backRect.setSize(sf::Vector2f(780, 228));
    backRect.setFillColor(sf::Color(255, 255, 255, 150));
    backRect.setPosition(position);
    window.draw(backRect);

    // draw any cards in the hand
    for(std::vector<Card*>::size_type i = 0; i != m_Cards.size(); ++i)
    {
        // if the card is not in transit 
        if(!m_Cards[i]->m_InTransit)
        {
            m_Cards[i]->getSprite().setPosition(position + sf::Vector2f(10 + 155 * i, 10));
            window.draw(m_Cards[i]->getSprite());
        }
    }
    */

    static int i = 0;
    if(i == 0)
    {
        std::cout << m_Cards.size() << " cards in the hand." << std::endl;
        std::cout << m_Cards[0]->getSprite().getPosition().x << " x-position" << std::endl;
        
        if(m_Cards[0]->getFrontTexture() == 0)
        {
            std::cout << "Front texture not set." << std::endl;
        } else {
            std::cout << "Front texture set." << std::endl;
        }

        if(m_Cards[0]->m_InTransit)
        {
            std::cout << "First card in transit." << std::endl;
        } else {
            std::cout << "First card not in transit" << std::endl;
        }

        if(m_Cards[0]->state() == CardState::FACE_UP)
        {
            std::cout << "Card 0 face up." << std::endl;

        } else if(m_Cards[0]->state() == CardState::FACE_DOWN)
        {
            std::cout << "Card 0 face down." << std::endl;

        } else {
            std::cout << "Card 0 unoriented." << std::endl;
        }
        ++i;
    }
    
}
