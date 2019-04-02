//source file for the GameBoard class from the GameBoard.hpp header file

#include "GameBoard.hpp"
#include <algorithm>
#include <iterator>


/*
****************************************
         methods for GameBoard
****************************************
*/

GameBoard::GameBoard(ResourceManager& resourceManager) : 
m_MainDeck(resourceManager),
m_JakortaDeck(resourceManager),
m_CardHolder(resourceManager)
{
    // we will start with just two players, for now
    m_numberOfPlayers = 2;

    // create arrays for players' different bits and bobs
    m_PlayerHands = new PlayerHand[m_numberOfPlayers];
    m_CharPools = new CharPool[m_numberOfPlayers];
    m_RepPools = new int[m_numberOfPlayers];
    m_HandSizes = new std::vector<Card*>::size_type[m_numberOfPlayers];
    m_PlayerRoles = new PlayerRole[m_numberOfPlayers];

    // set all hand sizes to 4
    for(size_t i = 0; i != m_numberOfPlayers; ++i)
        m_HandSizes[i] = 4;
    
    // set the player indices
    for(size_t i = 0; i != m_numberOfPlayers; ++i)
    {
        m_PlayerHands[i].m_playerIndex = i;
        m_CharPools[i].m_playerIndex = i;
        m_PlayerRoles[i].m_playerIndex = i;
    }

        
    

    // ** to be worked out ** 
    // set all the positions of things

    // Place the Jakorta cards into their deck
    m_JakortaDeck.placeOnTop(&(m_CardHolder.jakorta1));
    m_JakortaDeck.placeOnTop(&(m_CardHolder.jakorta2));
    m_JakortaDeck.placeOnTop(&(m_CardHolder.jakorta3));
    m_JakortaDeck.placeOnTop(&(m_CardHolder.jakorta4));
    m_JakortaDeck.placeOnTop(&(m_CardHolder.jakorta5));
    m_JakortaDeck.placeOnTop(&(m_CardHolder.jakorta6));

    // Place the other cards into the main deck
    m_MainDeck.placeOnTop(&(m_CardHolder.vehicle1));
    m_MainDeck.placeOnTop(&(m_CardHolder.vehicle2));
    m_MainDeck.placeOnTop(&(m_CardHolder.vehicle3));
    m_MainDeck.placeOnTop(&(m_CardHolder.vehicle4));
    m_MainDeck.placeOnTop(&(m_CardHolder.vehicle5));
    m_MainDeck.placeOnTop(&(m_CardHolder.vehicle6));
    m_MainDeck.placeOnTop(&m_CardHolder.drawer);
    m_MainDeck.placeOnTop(&m_CardHolder.scryer);
    m_MainDeck.placeOnTop(&m_CardHolder.sifter);
    m_MainDeck.placeOnTop(&m_CardHolder.hogger);
    m_MainDeck.placeOnTop(&m_CardHolder.smuggler);
    m_MainDeck.placeOnTop(&m_CardHolder.rumourmonger);
    m_MainDeck.placeOnTop(&m_CardHolder.muscle);
    m_MainDeck.placeOnTop(&m_CardHolder.supporter);
    m_MainDeck.placeOnTop(&m_CardHolder.squirrel);
    m_MainDeck.placeOnTop(&m_CardHolder.brawling1);
    m_MainDeck.placeOnTop(&m_CardHolder.brawling2);
    m_MainDeck.placeOnTop(&m_CardHolder.letsGo1);
    m_MainDeck.placeOnTop(&m_CardHolder.letsGo2);
    m_MainDeck.placeOnTop(&m_CardHolder.cruizing1);
    m_MainDeck.placeOnTop(&m_CardHolder.cruizing2);
    m_MainDeck.placeOnTop(&m_CardHolder.cruizing3);
    m_MainDeck.placeOnTop(&m_CardHolder.stop1);
    m_MainDeck.placeOnTop(&m_CardHolder.disposal1);
    m_MainDeck.placeOnTop(&m_CardHolder.disposal2);
    m_MainDeck.placeOnTop(&m_CardHolder.grapevine1);
    m_MainDeck.placeOnTop(&m_CardHolder.grapevine2);

    
    // Place the roles into the RolePool
    m_RolePool.placeOnTop(&m_CardHolder.broker);
    m_RolePool.placeOnTop(&m_CardHolder.spy);
    m_RolePool.placeOnTop(&m_CardHolder.brute);
    m_RolePool.placeOnTop(&m_CardHolder.scavenger);
    m_RolePool.placeOnTop(&m_CardHolder.odin);
    m_RolePool.placeOnTop(&m_CardHolder.mouth);

    // set the appropriate card scales
    m_CardInHand.m_CardScale = m_SMALL_SCALE;
    m_Discards.m_CardScale = m_SMALL_SCALE;
    m_MainDeck.m_CardScale = m_SMALL_SCALE;
    m_JakortaDeck.m_CardScale = m_SMALL_SCALE;
    m_RolePool.m_CardScale = m_LARGE_SCALE;
    for(size_t i = 0; i != m_numberOfPlayers; ++i)
    {
        m_PlayerHands[i].m_CardScale = m_SMALL_SCALE;
        m_CharPools[i].m_CardScale = m_SMALL_SCALE;
        m_PlayerRoles[i].m_CardScale = m_SMALL_SCALE;
    }

    


}

GameBoard::~GameBoard()
{
    delete[] m_PlayerHands;
    delete[] m_CharPools;
    delete[] m_RepPools;
    delete[] m_HandSizes;
    delete[] m_PlayerRoles;
}

void GameBoard::drawCard(size_t player)
{
    m_PlayerHands[player].placeOnTop(m_MainDeck.removeTopCard());
}

void GameBoard::discard(Card* card, size_t player)
{
    m_Discards.placeOnTop(card);
    m_PlayerHands[player].removeCard(card);
}

void GameBoard::gainRep(size_t player, int amount)
{
    m_RepPools[player] += amount;
}