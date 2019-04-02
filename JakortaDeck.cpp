//source file for the JakortaDeck class from the GameBoard header file

#include "GameBoard.hpp"
#include <algorithm>
#include <iterator>

/*
****************************************
         methods for JakortaDeck
****************************************
*/

JakortaDeck::JakortaDeck(ResourceManager& resourceManager)
{
    // set the back_texture pointer
    mp_backTexture = &(resourceManager.getTexture("back_jakorta"));
    
}

void JakortaDeck::placeOnTop(Card* card)
{
    // set card to correct state
    card->orient(CardState::FACE_DOWN);

    // scale the card correctly
    card->getSprite().scale(sf::Vector2f(m_CardScale, m_CardScale));

    // add card to top of deck
    m_Deck.push_back(card);
}

Card* JakortaDeck::returnTopCard()
{
    return m_Deck[m_Deck.size() - 1];
}

void JakortaDeck::shuffle()
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

void JakortaDeck::nextTurn()
{
    // terminate if there are no cards left in the deck
    if(m_Deck.size() == 0)
        return;
    
    // turn the next card from the top of the deck
    Card* nextCard = m_Deck[m_Deck.size() - 1];
    nextCard->orient(CardState::FACE_UP);
    m_turnCards.push_back(nextCard);
    m_Deck.pop_back();
}

void JakortaDeck::reset()
{
    // add all turned cards back to the deck
    for(auto i = m_turnCards.begin(); i != m_turnCards.end(); ++i)
    {
        (*i)->orient(CardState::FACE_DOWN);
        m_Deck.push_back(*i);
    }
    // reset turned cards vector
    m_turnCards.clear();

    // shuffle the deck
    shuffle();
}

void JakortaDeck::draw(sf::RenderWindow& window, sf::Vector2f position)
{
    // if there are cards in the deck
    if(m_Deck.size() != 0)
    {
        // draw the top card
        returnTopCard()->getSprite().setPosition(position);
        window.draw(returnTopCard()->getSprite());
        
    }

    window.draw(returnTopCard()->getSprite());

    /*
    // draw any cards that have been turned
    for(std::vector<Card*>::size_type i = 0; i != m_turnCards.size(); ++i)
    {
        sf::Sprite cardSprite = m_turnCards[i]->getSprite();
        cardSprite.setPosition(location + sf::Vector2f(155 * (i + 1), 0));
        window.draw(cardSprite);
    }
    */
    
}