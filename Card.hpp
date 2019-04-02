#ifndef __GUARD_CARD
#define __GUARD_CARD
// header file for the Card class

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class GameBoard;

enum class CardState
{
    FACE_DOWN, FACE_UP
};

class Card
{
    public:
        // Constructors / destructors for Card class
        Card();
        virtual ~Card() {};

        // getters
        virtual sf::Sprite& getSprite();
        bool m_InTransit;
        bool m_Highlighted;
        CardState state() const;
        sf::Texture* const getFrontTexture();
        sf::Texture* const getBackTexture();
        void orient(CardState);


    protected:
        sf::Texture* m_textureFront;
        sf::Texture* m_textureBack;


    private:
        sf::Sprite m_Sprite;
        CardState m_State;
};

/*
****************************************
        Charactors
****************************************
*/


enum class CharState
{
    READY, EXHAUSTED
};

class Character : public Card
{
    public:
        Character() { m_CharState = CharState::READY; }
        ~Character() {}

        void play(GameBoard*);
        void trash(GameBoard*);
        virtual void useCharracter(GameBoard*) {};
        //sf::Sprite getSprite();
        CharState m_CharState;
};

class Drawer : public Character
{
    public:
        Drawer(ResourceManager& resourceManager)
        {
            m_textureFront = &(resourceManager.getTexture("drawer"));
            m_textureBack = &(resourceManager.getTexture("back_normal"));
        }
        ~Drawer() {};
};


class Scryer : public Character
{
    public:
        Scryer(ResourceManager& resourceManager)
        {
            m_textureFront = &(resourceManager.getTexture("scryer"));
            m_textureBack = &(resourceManager.getTexture("back_normal"));
        }
        ~Scryer() {};
};


class Sifter : public Character
{
    public:
        Sifter(ResourceManager& resourceManager)
        {
            m_textureFront = &(resourceManager.getTexture("sifter"));
            m_textureBack = &(resourceManager.getTexture("back_normal"));
        }
        ~Sifter() {};
};


class Hogger : public Character
{
    public:
        Hogger(ResourceManager& resourceManager)
        {
            m_textureFront = &(resourceManager.getTexture("hogger"));
            m_textureBack = &(resourceManager.getTexture("back_normal"));
        }
        ~Hogger() {};
};


class Smuggler : public Character
{
    public:
        Smuggler(ResourceManager& resourceManager)
        {
            m_textureFront = &(resourceManager.getTexture("smuggler"));
            m_textureBack = &(resourceManager.getTexture("back_normal"));
        }
        ~Smuggler() {};
};


class Rumourmonger : public Character
{
    public:
        Rumourmonger(ResourceManager& resourceManager)
        {
            m_textureFront = &(resourceManager.getTexture("rumourmonger"));
            m_textureBack = &(resourceManager.getTexture("back_normal"));
        }
        ~Rumourmonger() {};
};


class Muscle : public Character
{
    public:
        Muscle(ResourceManager& resourceManager)
        {
            m_textureFront = &(resourceManager.getTexture("muscle"));
            m_textureBack = &(resourceManager.getTexture("back_normal"));
        }
        ~Muscle() {};
};


class Supporter : public Character
{
    public:
        Supporter(ResourceManager& resourceManager)
        {
            m_textureFront = &(resourceManager.getTexture("supporter"));
            m_textureBack = &(resourceManager.getTexture("back_normal"));
        }
        ~Supporter() {};
};


class Squirrel : public Character
{
    public:
        Squirrel(ResourceManager& resourceManager)
        {
            m_textureFront = &(resourceManager.getTexture("squirrel"));
            m_textureBack = &(resourceManager.getTexture("back_normal"));
        }
        ~Squirrel() {};
};

/*
****************************************
        Actions
****************************************
*/

class Action : public Card
{
    public:
        ~Action() {};
        virtual void use(GameBoard& gameBoard) {};
        
};

class Brawling : public Action
{
    public:
        Brawling(ResourceManager& resourseManager)
        {
            m_textureFront = &resourseManager.getTexture("brawling");
            m_textureBack = &resourseManager.getTexture("back_normal");
        }
        ~Brawling() {};
};

class LetsGo : public Action
{
    public:
        LetsGo(ResourceManager& resourceManager)
        {
            m_textureFront = &resourceManager.getTexture("lets_go");
            m_textureBack = &resourceManager.getTexture("back_normal");
        }
        ~LetsGo() {};
};

class Cruizing : public Action
{
    public:
        Cruizing(ResourceManager& resourceManager)
        {
            m_textureFront = &resourceManager.getTexture("cruizing");
            m_textureBack = &resourceManager.getTexture("back_normal");
        }
        ~Cruizing() {};
};

class Stop : public Action
{
    public:
        Stop(ResourceManager& resourceManager)
        {
            m_textureFront = &resourceManager.getTexture("stop");
            m_textureBack = &resourceManager.getTexture("back_normal");
        }
        ~Stop() {};
};

class Disposal : public Action
{
    public:
        Disposal(ResourceManager& resourceManager)
        {
            m_textureFront = &resourceManager.getTexture("disposal");
            m_textureBack = & resourceManager.getTexture("back_normal");
        }
        ~Disposal() {};
};

class Grapevine : public Action
{
    public:
        Grapevine(ResourceManager& resourceManager)
        {
            m_textureFront = &resourceManager.getTexture("grapevine");
            m_textureBack = &resourceManager.getTexture("back_normal");
        }
        ~Grapevine() {};
};


/*
****************************************
        Vehicle Parts
****************************************
*/

enum class VehicleConnector
{
    SQUARE, CIRCLE, TRIANGLE, NONE
};

enum class CardSide
{
    TOP, RIGHT, BOTTOM, LEFT
};

class VehiclePart : public Card
{
    public:
        ~VehiclePart() {};

        void play(GameBoard*);
        void trash(GameBoard*);
        void rotate();
        VehicleConnector getConnection(CardSide side) const;

    protected:
        std::map<CardSide, VehicleConnector> m_Connectivity;


    private:
        int m_RotationAngle;
        
};

class VehiclePart1 : public VehiclePart
{
    public:
        VehiclePart1(ResourceManager& resouceManager)
        {
            m_textureBack = &(resouceManager.getTexture("back_normal"));
            m_textureFront = &(resouceManager.getTexture("vehicle1"));

            m_Connectivity[CardSide::TOP] = VehicleConnector::TRIANGLE;
            m_Connectivity[CardSide::RIGHT] = VehicleConnector::TRIANGLE;
            m_Connectivity[CardSide::BOTTOM] = VehicleConnector::CIRCLE;
            m_Connectivity[CardSide::LEFT] = VehicleConnector::CIRCLE;
        }
};

class VehiclePart2 : public VehiclePart
{
    public:
        VehiclePart2(ResourceManager& resouceManager)
        {
            m_textureBack = &(resouceManager.getTexture("back_normal"));
            m_textureFront = &(resouceManager.getTexture("vehicle2"));

            m_Connectivity[CardSide::TOP] = VehicleConnector::TRIANGLE;
            m_Connectivity[CardSide::RIGHT] = VehicleConnector::TRIANGLE;
            m_Connectivity[CardSide::BOTTOM] = VehicleConnector::NONE;
            m_Connectivity[CardSide::LEFT] = VehicleConnector::SQUARE;
        }
};

class VehiclePart3 : public VehiclePart
{
    public:
        VehiclePart3(ResourceManager& resouceManager)
        {
            m_textureBack = &(resouceManager.getTexture("back_normal"));
            m_textureFront = &(resouceManager.getTexture("vehicle3"));

            m_Connectivity[CardSide::TOP] = VehicleConnector::SQUARE;
            m_Connectivity[CardSide::RIGHT] = VehicleConnector::SQUARE;
            m_Connectivity[CardSide::BOTTOM] = VehicleConnector::NONE;
            m_Connectivity[CardSide::LEFT] = VehicleConnector::SQUARE;
        }
};

class VehiclePart4 : public VehiclePart
{
    public:
        VehiclePart4(ResourceManager& resouceManager)
        {
            m_textureBack = &(resouceManager.getTexture("back_normal"));
            m_textureFront = &(resouceManager.getTexture("vehicle4"));

            m_Connectivity[CardSide::TOP] = VehicleConnector::SQUARE;
            m_Connectivity[CardSide::RIGHT] = VehicleConnector::SQUARE;
            m_Connectivity[CardSide::BOTTOM] = VehicleConnector::SQUARE;
            m_Connectivity[CardSide::LEFT] = VehicleConnector::SQUARE;
        }
};

class VehiclePart5 : public VehiclePart
{
    public:
        VehiclePart5(ResourceManager& resouceManager)
        {
            m_textureBack = &(resouceManager.getTexture("back_normal"));
            m_textureFront = &(resouceManager.getTexture("vehicle5"));

            m_Connectivity[CardSide::TOP] = VehicleConnector::CIRCLE;
            m_Connectivity[CardSide::RIGHT] = VehicleConnector::NONE;
            m_Connectivity[CardSide::BOTTOM] = VehicleConnector::SQUARE;
            m_Connectivity[CardSide::LEFT] = VehicleConnector::CIRCLE;
        }
};

class VehiclePart6 : public VehiclePart
{
    public:
        VehiclePart6(ResourceManager& resouceManager)
        {
            m_textureBack = &(resouceManager.getTexture("back_normal"));
            m_textureFront = &(resouceManager.getTexture("vehicle6"));

            m_Connectivity[CardSide::TOP] = VehicleConnector::NONE;
            m_Connectivity[CardSide::RIGHT] = VehicleConnector::NONE;
            m_Connectivity[CardSide::BOTTOM] = VehicleConnector::SQUARE;
            m_Connectivity[CardSide::LEFT] = VehicleConnector::NONE;
        }
};

/*
****************************************
        Jakorta's Allies
****************************************
*/

class JakortaAlly : public Card
{
    public:
        JakortaAlly() {}
        ~JakortaAlly() {};

        //virtual void allyEvent(GameBoard*) = 0;
        //virtual void allyBlackoutEvent(GameBoard*) = 0;
};

class Jakorta1 : public JakortaAlly
{
    public:
        Jakorta1() {};
        Jakorta1(ResourceManager&);
        ~Jakorta1() {};

        //void allyEvent(GameBoard* p_gameBoard);
        //void allyBlackoutEvent(GameBoard* p_gameBoard);
};

class Jakorta2 : public JakortaAlly
{
    public:
        Jakorta2() {};
        Jakorta2(ResourceManager&);
        ~Jakorta2() {};

        //void allyEvent(GameBoard* p_gameBoard);
        //void allyBlackoutEvent(GameBoard* p_gameBoard);
};

class Jakorta3 : public JakortaAlly
{
    public:
        Jakorta3() {};
        Jakorta3(ResourceManager&);
        ~Jakorta3() {};

        //void allyEvent(GameBoard* p_gameBoard);
        //void allyBlackoutEvent(GameBoard* p_gameBoard);
};

class Jakorta4 : public JakortaAlly
{
    public:
        Jakorta4() {};
        Jakorta4(ResourceManager&);
        ~Jakorta4() {};

        //void allyEvent(GameBoard* p_gameBoard);
        //void allyBlackoutEvent(GameBoard* p_gameBoard);
};

class Jakorta5 : public JakortaAlly
{
    public:
        Jakorta5() {};
        Jakorta5(ResourceManager&);
        ~Jakorta5() {};

        //void allyEvent(GameBoard* p_gameBoard);
        //void allyBlackoutEvent(GameBoard* p_gameBoard);
};

class Jakorta6 : public JakortaAlly
{
    public:
        Jakorta6() {};
        Jakorta6(ResourceManager&);
        ~Jakorta6() {};

        //void allyEvent(GameBoard* p_gameBoard);
        //void allyBlackoutEvent(GameBoard* p_gameBoard);
};

/*
****************************************
        Roles
****************************************
*/

class Role : public Card
{
    public:
        Role() {};
        ~Role() {};
        virtual void useRole(GameBoard& gameBoard) {};
    
    private:

};

class Broker : public Role
{
    public:
        Broker(ResourceManager& resourceManager)
        {
            m_textureFront = &resourceManager.getTexture("role_broker");
            m_textureBack = &resourceManager.getTexture("back_normal");
        }
        ~Broker() {};
};


class Brute : public Role
{
    public:
        Brute(ResourceManager& resourceManager)
        {
            m_textureFront = &resourceManager.getTexture("role_brute");
            m_textureBack = &resourceManager.getTexture("back_normal");
        }
        ~Brute() {};
};


class Mouth : public Role
{
    public:
        Mouth(ResourceManager& resourceManager)
        {
            m_textureFront = &resourceManager.getTexture("role_mouth");
            m_textureBack = &resourceManager.getTexture("back_normal");
        }
        ~Mouth() {};
};


class Odin : public Role
{
    public:
        Odin(ResourceManager& resourceManager)
        {
            m_textureFront = &resourceManager.getTexture("role_odin");
            m_textureBack = &resourceManager.getTexture("back_normal");
        }
        ~Odin() {};
};


class Scavenger : public Role
{
    public:
        Scavenger(ResourceManager& resourceManager)
        {
            m_textureFront = &resourceManager.getTexture("role_scavenger");
            m_textureBack = &resourceManager.getTexture("back_normal");
        }
        ~Scavenger() {};
};


class Spy : public Role
{
    public:
        Spy(ResourceManager& resourceManager)
        {
            m_textureFront = &resourceManager.getTexture("role_spy");
            m_textureBack = &resourceManager.getTexture("back_normal");
        }
        ~Spy() {};
};

/*
****************************************
        CardHolder
****************************************
*/

class CardHolder
{
    public:

        CardHolder(ResourceManager& resourceManager);
        ~CardHolder() {};

        // Jakorta's Allies
        Jakorta1        jakorta1;
        Jakorta2        jakorta2;
        Jakorta3        jakorta3;
        Jakorta4        jakorta4;
        Jakorta5        jakorta5;
        Jakorta6        jakorta6;

        // Vehicle Parts
        VehiclePart1    vehicle1;
        VehiclePart2    vehicle2;
        VehiclePart3    vehicle3;
        VehiclePart4    vehicle4;
        VehiclePart5    vehicle5;
        VehiclePart6    vehicle6;

        // Characters
        Drawer          drawer;
        Scryer          scryer;
        Sifter          sifter;
        Hogger          hogger;
        Smuggler        smuggler;
        Rumourmonger    rumourmonger;
        Muscle          muscle;
        Supporter       supporter;
        Squirrel        squirrel;

        // Actions
        Brawling        brawling1;
        Brawling        brawling2;
        LetsGo          letsGo1;
        LetsGo          letsGo2;
        Cruizing        cruizing1;
        Cruizing        cruizing2;
        Cruizing        cruizing3;
        Stop            stop1;
        Stop            stop2;
        Disposal        disposal1;
        Disposal        disposal2;
        Grapevine       grapevine1;
        Grapevine       grapevine2;

        // Roles
        Broker          broker;
        Brute           brute;
        Mouth           mouth;
        Odin            odin;
        Scavenger       scavenger;
        Spy             spy;

};


#endif