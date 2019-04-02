// source file for TextureManager class

#include "TextureManager.hpp"
#include <stdexcept>
#include <fstream>


TextureManager::TextureManager()
{
    // load textures
    loadTextures();

}

TextureManager::~TextureManager()
{

}


void TextureManager::addTexture(const std::string& texture_id, const std::string& texture_path)
{
    // check to see if the texture has already been added
    auto it = texture_map.find(texture_id);
    if(it != texture_map.end())
        throw std::logic_error(texture_path + " has already been added.");

    // load the Texture from file
    sf::Texture texture;
    if(!texture.loadFromFile(texture_path))
        throw std::logic_error("Could not load texture " + texture_path);
    
    // add the texture to the map
    texture_map[texture_id] = texture;
}


sf::Texture& TextureManager::getTexture(const std::string& texture_id)
{
    // locate the correct texture
    auto it = texture_map.find(texture_id);

    // make sure we found it
    if(it == texture_map.end())
        throw std::logic_error("Texture " + texture_id + " does not exist.");

    return it->second;
}

void TextureManager::loadTextures()
{
        addTexture("background", "graphics/background.png");
        addTexture("brawling", "graphics/cards.2/brawling.png");
        addTexture("cruizing", "graphics/cards.2/cruizing.png");
        addTexture("disposal", "graphics/cards.2/disposal.png");
        addTexture("drawer", "graphics/cards.2/drawer.png");
        addTexture("grapevine", "graphics/cards.2/grapevine.png");
        addTexture("hogger", "graphics/cards.2/hogger.png");
        addTexture("jakorta1", "graphics/cards.2/jakorta1.png");
        addTexture("jakorta2", "graphics/cards.2/jakorta2.png");
        addTexture("jakorta3", "graphics/cards.2/jakorta3.png");
        addTexture("jakorta4", "graphics/cards.2/jakorta4.png");
        addTexture("jakorta5", "graphics/cards.2/jakorta5.png");
        addTexture("jakorta6", "graphics/cards.2/jakorta6.png");
        addTexture("lets_go", "graphics/cards.2/lets_go.png");
        addTexture("muscle", "graphics/cards.2/muscle.png");
        addTexture("role_broker", "graphics/cards.2/role_broker.png");
        addTexture("role_brute", "graphics/cards.2/role_brute.png");
        addTexture("role_mouth", "graphics/cards.2/role_mouth.png");
        addTexture("role_odin", "graphics/cards.2/role_odin.png");
        addTexture("role_scavenger", "graphics/cards.2/role_scavenger.png");
        addTexture("role_spy", "graphics/cards.2/role_spy.png");
        addTexture("rumourmonger", "graphics/cards.2/rumourmonger.png");
        addTexture("scryer", "graphics/cards.2/scryer.png");
        addTexture("sifter", "graphics/cards.2/sifter.png");
        addTexture("smuggler", "graphics/cards.2/smuggler.png");
        addTexture("squirrel", "graphics/cards.2/squirrel.png");
        addTexture("stop", "graphics/cards.2/stop.png");
        addTexture("supporter", "graphics/cards.2/supporter.png");
        addTexture("vehicle1", "graphics/cards.2/vehicle1.png");
        addTexture("vehicle2", "graphics/cards.2/vehicle2.png");
        addTexture("vehicle3", "graphics/cards.2/vehicle3.png");
        addTexture("vehicle4", "graphics/cards.2/vehicle4.png");
        addTexture("vehicle5", "graphics/cards.2/vehicle5.png");
        addTexture("vehicle6", "graphics/cards.2/vehicle6.png");
        addTexture("back_jakorta", "graphics/cards.1/back_jakorta.png");
        addTexture("back_normal", "graphics/cards.1/back_normal.png");
}
