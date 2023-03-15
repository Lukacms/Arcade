/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLTexture
*/

#include <arcade/SFML/entities/SFMLTexture.hh>
#include <exception>

/* Constructor & Destructor */

/* Methods */

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
