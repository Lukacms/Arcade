/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLSprite
*/

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <arcade/SFML/entities/SFMLSprite.hh>
#include <arcade/SFML/entities/SFMLTexture.hh>

/* Constructor && Destructor */

/* Methods */

void arc::SFMLSprite::createEntity(__attribute__((unused))  std::string str) {}

void arc::SFMLSprite::createEntity(IEntity &texture)
{
    arc::SFMLTexture *sfml_texture = dynamic_cast<arc::SFMLTexture *>(&texture);
    sf::IntRect rect = sf::IntRect{this->entityRect.getLeft(), this->entityRect.getTop(),
        this->entityRect.getWidth(), this->entityRect.getHeight()};

//    if (sfml_texture == nullptr)
//        throw error;
    this->m_sprite = sf::Sprite{sfml_texture->getTexture()};
    this->m_sprite.setTextureRect(rect);
}

void arc::SFMLSprite::destroyEntity() {}

void arc::SFMLSprite::drawEntity(__attribute__((unused))IWindow &window)
{
    sf::Vector2f vector = sf::Vector2f{this->entityPosition.getVectorX(), this->entityPosition.getVectorY()};

    this->m_sprite.setPosition(vector);
    // Dynamic Cast de la window + Check si nullptr + draw dans la window
}

