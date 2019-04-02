#ifndef __GUARD_RESOURCE_MANAGER
#define __GUARD_RESOURCE_MANAGER
// header file for the overall resource manager
#include "TextureManager.hpp"


class ResourceManager
{
    public:
        ResourceManager();
        ~ResourceManager();

        sf::Texture& getTexture(const std::string& texture_id) { return m_texture_manager.getTexture(texture_id); }


    private:
        TextureManager m_texture_manager;

};


#endif