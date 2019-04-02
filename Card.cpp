// source file for Card.hpp

#include "Card.hpp"

using namespace sf;

Card::Card()
{
    // set pointers to null initially
    m_textureBack = 0;
    m_textureFront = 0;

    m_InTransit = false;
    m_Highlighted = false;

}

sf::Sprite& Card::getSprite()
{
    return m_Sprite;
}

sf::Texture* const Card::getFrontTexture()
{
    return m_textureFront;
}

sf::Texture* const Card::getBackTexture()
{
    return m_textureBack;
}

void Card::orient(CardState state)
{
    // set the Sprite to the appropriate texture
    switch(state)
    {
        case CardState::FACE_UP:
            m_Sprite.setTexture(*m_textureFront);
            break;
        
        case CardState::FACE_DOWN:
            m_Sprite.setTexture(*m_textureBack);
            break;
    }

    // set the Card State
    m_State = state;
}

CardState Card::state() const
{
    return m_State;
}

/*
****************************************
        Character
****************************************
*/
/*
sf::Sprite Character::getSprite()
{
    sf::Sprite ret;

    if(m_CharState == CharState::READY)
    {
        switch(m_State)
        {
            case CardState::FACE_DOWN:
            {
                ret.setTexture(*m_textureBack);
                ret.scale(sf::Vector2f(1.2f, 1.2f));
                break;
            }

            case CardState::FACE_UP:
            {
                ret.setTexture(*m_textureFront);
                ret.scale(sf::Vector2f(0.2f, 0.2f));
                break;
            }
        }
    } else {
        ret.setTexture(*m_textureFront);
        ret.scale(sf::Vector2f(0.2f, 0.2f));
        ret.setRotation(90);
    }

    return ret;
}
*/

/*
****************************************
        Actions
****************************************
*/



/*
****************************************
        VehiclePart
****************************************
*/

VehicleConnector VehiclePart::getConnection(CardSide side) const
{
    return m_Connectivity.find(side)->second;
}




/*
****************************************
        Jakorta's Allies
****************************************
*/


Jakorta1::Jakorta1(ResourceManager& resourceManager)
{
    // set texture pointers
    m_textureFront = &resourceManager.getTexture("jakorta1");
    m_textureBack = &resourceManager.getTexture("back_jakorta");
}

Jakorta2::Jakorta2(ResourceManager& resourceManager)
{
    // set texture pointers
    m_textureFront = &resourceManager.getTexture("jakorta2");
    m_textureBack = &resourceManager.getTexture("back_jakorta");
}

Jakorta3::Jakorta3(ResourceManager& resourceManager)
{
    // set texture pointers
    m_textureFront = &resourceManager.getTexture("jakorta3");
    m_textureBack = &resourceManager.getTexture("back_jakorta");
}

Jakorta4::Jakorta4(ResourceManager& resourceManager)
{
    // set texture pointers
    m_textureFront = &resourceManager.getTexture("jakorta4");
    m_textureBack = &resourceManager.getTexture("back_jakorta");
}

Jakorta5::Jakorta5(ResourceManager& resourceManager)
{
    // set texture pointers
    m_textureFront = &resourceManager.getTexture("jakorta5");
    m_textureBack = &resourceManager.getTexture("back_jakorta");
}

Jakorta6::Jakorta6(ResourceManager& resourceManager)
{
    // set texture pointers
    m_textureFront = &resourceManager.getTexture("jakorta6");
    m_textureBack = &resourceManager.getTexture("back_jakorta");
}

/*
****************************************
        Roles
****************************************
*/


/*
****************************************
        CardHolder
****************************************
*/

CardHolder::CardHolder(ResourceManager& resourceManager):
jakorta1(resourceManager),
jakorta2(resourceManager),
jakorta3(resourceManager),
jakorta4(resourceManager),
jakorta5(resourceManager),
jakorta6(resourceManager),
vehicle1(resourceManager),
vehicle2(resourceManager),
vehicle3(resourceManager),
vehicle4(resourceManager),
vehicle5(resourceManager),
vehicle6(resourceManager),
drawer(resourceManager),
scryer(resourceManager),
sifter(resourceManager),
hogger(resourceManager),
smuggler(resourceManager),
rumourmonger(resourceManager),
muscle(resourceManager),
supporter(resourceManager),
squirrel(resourceManager),
brawling1(resourceManager),
brawling2(resourceManager),
letsGo1(resourceManager),
letsGo2(resourceManager),
cruizing1(resourceManager),
cruizing2(resourceManager),
cruizing3(resourceManager),
stop1(resourceManager),
stop2(resourceManager),
disposal1(resourceManager),
disposal2(resourceManager),
grapevine1(resourceManager),
grapevine2(resourceManager),
broker(resourceManager),
brute(resourceManager),
mouth(resourceManager),
odin(resourceManager),
scavenger(resourceManager),
spy(resourceManager)
{

}
