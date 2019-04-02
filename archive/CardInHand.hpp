#ifndef GUARD__CARD_IN_HAND
#define GUARD__CARD_IN_HAND
// header file for the CardInHand class

#include "Card.hpp"
#include "GameBoard.hpp"


enum class PickupLocation
{
    MAIN_DECK, 
    CHAR_POOL, 
    PLAYER_HAND,  
    //COMPOUND, 
    NONE
};

enum class DropoffLocation
{
    COMPOUND, 
    DISCARDS, 
    CHARPOOL
    // COMPOUND
};

class CardInHand
{
    public:
        CardInHand();
        ~CardInHand();

        void pickUpCard(Card* card, GameBoard& gameboard, PickupLocation location, size_t index);
        void placeCard(bool valid, GameBoard& gameBoard, DropoffLocation destination, size_t index);

        bool holdingCard() const { return mp_card; }
    
    private:
        Card*           mp_card;
        MainDeck*       mp_MainDeckCopy;
        PlayerHand*     mp_PlayerHandCopy;
        CharPool*       mp_CharPoolCopy;
        size_t          m_playerIndex;
        PickupLocation  m_PickupLoaction;
};

/*
****************************************
         methods for CardInHand
****************************************
*/

CardInHand::CardInHand()
{
    // set all pointers to null
    mp_card = 0;
    mp_MainDeckCopy = 0;
    mp_CharPoolCopy = 0;
    mp_PlayerHandCopy = 0;

    // null PlayerIndex is 100
    m_playerIndex = 100;

    m_PickupLoaction = PickupLocation::NONE;

}

CardInHand::~CardInHand()
{
    // delete pointers
}

void CardInHand::pickUpCard(Card* card, GameBoard& gameBoard, PickupLocation location, size_t index = 0)
{
    // store the card
    mp_card = card;

    // store the pickup location
    m_PickupLoaction = location;

    // store the original state of the pickup location
    switch(location)
    {

        case PickupLocation::MAIN_DECK:
            // store the main deck state
            mp_MainDeckCopy = new MainDeck(gameBoard.m_MainDeck);
            break;
        
        case PickupLocation::CHAR_POOL:
            // store the appropriate charpool state and player index
            m_playerIndex = index;
            mp_CharPoolCopy = new CharPool(gameBoard.m_CharPools[index]);
            break;
        
        case PickupLocation::PLAYER_HAND:
            // store the appropriate player hand state and index
            m_playerIndex = index;
            mp_PlayerHandCopy = new PlayerHand(gameBoard.m_PlayerHands[index]);
            break;

        case PickupLocation::NONE:
            break;
    }

}

void CardInHand::placeCard(bool valid, GameBoard& gameBoard, DropoffLocation destination, size_t index = 0)
{
    if (valid)
    {
        // add the card to the appropriate loaction
        switch(destination)
        {
            case DropoffLocation::DISCARDS:
                gameBoard.m_Discards.placeOnTop(mp_card);
                break;
            
            case DropoffLocation::CHARPOOL:
                gameBoard.m_CharPools[index].placeOnTop(mp_card);
                break;
            
            //case DropoffLocation::COMPOUND
            
        }

    } else {

        // restore previous gameboard states
        switch(m_PickupLoaction)
        {
            case PickupLocation::MAIN_DECK:
                gameBoard.m_MainDeck = *mp_MainDeckCopy;
                break;
            
            case PickupLocation::CHAR_POOL:
                gameBoard.m_CharPools[m_playerIndex] = *mp_CharPoolCopy;
                break;
            
            case PickupLocation::PLAYER_HAND:
                gameBoard.m_PlayerHands[m_playerIndex] = *mp_PlayerHandCopy;
                break;

            case PickupLocation::NONE:
                break;
            
            //case PickupLocation::COMPOUND
        }
    }

    // release stored memory
    delete mp_CharPoolCopy;
    delete mp_MainDeckCopy;
    delete mp_PlayerHandCopy;

    // reset the pointers
    mp_card = 0;
    mp_CharPoolCopy = 0;
    mp_MainDeckCopy = 0;
    mp_PlayerHandCopy = 0;

    // reset PickupLocation and Player Index
    m_PickupLoaction = PickupLocation::NONE;
    m_playerIndex = 100;
}

#endif