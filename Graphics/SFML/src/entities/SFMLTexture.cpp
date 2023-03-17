/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLTexture
*/

#include <SFML/entities/SFMLTexture.hh>
#include <exception>

/* Constructor & Destructor */

/* Methods */

/**
 * Create a texture with the given filepath.
 * @param str The string that represents the path to the texture file.
 */
void arc::SFMLTexture::createEntity(std::string str)
{
    try {
        this->m_texture.loadFromFile(str);
    }
    catch (std::exception) {
        throw;
    }
}

void arc::SFMLTexture::createEntity(__attribute__((unused))IEntity &texture) {}

void arc::SFMLTexture::destroyEntity() {}

void arc::SFMLTexture::drawEntity(__attribute__((unused))IWindow &window) {}
