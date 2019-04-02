#ifndef GUARD__GAMEBOARD_HPP
#define GUARD__GAMEBOARD_HPP

#include <vector>
#include <typeinfo>
#include "Card.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


class PlayerHand
{
    friend class GameBoard;

    public:
        PlayerHand() {};
        ~PlayerHand() {};

        void placeOnTop(Card* card);
        void removeCard(Card* card);
        void returnToDeck(std::vector<Card*> deck);
        Card* randomCard();
        std::vector<Card*>::size_type numberOfCards() const;
        size_t getIndex() { return m_playerIndex; }

        void draw(sf::RenderWindow& window, sf::Vector2f position, ResourceManager& resourceManager);


    private:
        std::vector<Card*>  m_Cards;
        size_t              m_playerIndex;
        float               m_CardScale;
};

class CharPool
{
    friend class GameBoard;

    public:
        ~CharPool() {};
        CharPool() {};
        CharPool(const CharPool& charPool);

        void placeOnTop(Card* card);
        void removeCard(Card* card);
        void returnToDeck(std::vector<Card*> deck);
        size_t getIndex() const { return m_playerIndex; }

        void draw(sf::RenderWindow window);

    private:
        std::vector<Card*> m_Charactors;
        size_t m_playerIndex;
        float m_CardScale;
};

class MainDeck
{
    friend class GameBoard;

    public:
        MainDeck() {};
        MainDeck(ResourceManager& resourceManager) 
        { 
            mp_backTexture = &resourceManager.getTexture("back_normal"); 
        }
        ~MainDeck() {};
        MainDeck(const MainDeck&);

        void shuffle();
        void placeOnTop(Card*);
        void placeOnBottom(Card*);
        Card* removeTopCard();
        Card* returnTopCard();
        void highlight(sf::Vector2i mousePosition);
        void draw(sf::RenderWindow& window, sf::Vector2f position);

    private:
        std::vector<Card*> m_Deck;
        sf::Texture* mp_backTexture;
        float m_CardScale;
};

class JakortaDeck
{
    friend class GameBoard;

    public:
        JakortaDeck() {};
        JakortaDeck(ResourceManager& resourceManager);
        ~JakortaDeck() {};

        void shuffle();
        void placeOnTop(Card*);
        Card* returnTopCard();
        void nextTurn();
        void reset();
        bool isEmpty() { return m_Deck.size() == 0; }

        void draw(sf::RenderWindow& window, sf::Vector2f location);

    private:
        std::vector<Card*> m_Deck;
        std::vector<Card*> m_turnCards;
        sf::Texture* mp_backTexture;
        float m_CardScale;
};

class Discards
{
    friend class GameBoard;

    public:
        Discards() {};
        ~Discards() {};
    
        void placeOnTop(Card* card);
        Card* topCard();
        void returnToDeck(std::vector<Card*> deck);

    private:
        std::vector<Card*> m_Cards;
        float m_CardScale;
};

class CardInHand
{
    friend class GameBoard;

    public:
        CardInHand() { m_Card = 0; };
        ~CardInHand() {};
    
        void addCard(Card* card);
        void removeCard();

        void draw(sf::RenderWindow& window, sf::Vector2i position);

    private:
        Card* m_Card;
        float m_CardScale;
};

class PlayerRole
{
    friend class GameBoard;

    public:
        PlayerRole() {};
        ~PlayerRole() {};

        void addCard(Card*);
        void draw(sf::RenderWindow& window, sf::Vector2f position);
    
    private:
        Card* m_Card;
        float m_CardScale;
        size_t m_playerIndex;
};

class RolePool
{
    friend class GameBoard;
    
    public:
        RolePool() {};
        ~RolePool() {};

        void placeOnTop(Card*);
        void setSprites(sf::Vector2f position);
        void draw(sf::RenderWindow& window);
        void highlight(sf::Vector2i mousePosition);

    private:
        std::vector<Card*> m_Cards;
        float m_CardScale;
};

class GameBoard
{
    public:
        GameBoard(ResourceManager& resourceManager);
        ~GameBoard();

        void drawCard(size_t player);
        void discard(Card* card, size_t player);
        void gainRep(size_t player, int amount);
        size_t const numerOfPlayers() { return m_numberOfPlayers; }

        MainDeck                        m_MainDeck;
        JakortaDeck                     m_JakortaDeck;
        Discards                        m_Discards;
        RolePool                        m_RolePool;
        CardInHand                      m_CardInHand;
        PlayerHand*                     m_PlayerHands;
        CharPool*                       m_CharPools;
        PlayerRole*                     m_PlayerRoles;
        int*                            m_RepPools;
        std::vector<Card*>::size_type*  m_HandSizes;

    private:
        size_t              m_numberOfPlayers;

        // Card Scales
        const float m_LARGE_SCALE = 0.34f;
        const float m_SMALL_SCALE = 0.2f;
        
        //GameState

        // The card objects
        CardHolder m_CardHolder;
};


#endif