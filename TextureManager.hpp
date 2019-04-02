#ifndef __GUARD_TEXTURE_MANAGER
#define __GUARD_TEXTURE_MANAGER
// header file for the TextureManager class

#include <SFML/Graphics.hpp>
#include <map>

class TextureManager
{
    public:
        // constructors / destructors
        TextureManager();
        ~TextureManager();

        // interface functions
        void addTexture(const std::string& texture_id, const std::string& texture_path);
        sf::Texture& getTexture(const std::string& texture_id);
        void loadTextures();

    private:
        
        std::map<const std::string, sf::Texture> texture_map;

};


#endif