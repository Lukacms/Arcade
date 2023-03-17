/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLSprite
*/

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/SFMLWindow.hh>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/entities/SFMLSprite.hh>
#include <SFML/entities/SFMLTexture.hh>

/* Constructor && Destructor */

/* Methods */

void arc::SFMLSprite::createEntity(__attribute__((unused))  std::string str) {}

/**
 * Create a new sprite with the texture
 * @param texture The texture to create the sprite with.
 */
void arc::SFMLSprite::createEntity(IEntity &entity)
{
    arc::SFMLTexture *sfml_texture = dynamic_cast<arc::SFMLTexture *>(&entity);
    sf::IntRect rect = sf::IntRect{this->entityRect.getLeft(), this->entityRect.getTop(),
        this->entityRect.getWidth(), this->entityRect.getHeight()};

    if (sfml_texture == nullptr)
        throw;
    this->m_sprite = sf::Sprite{sfml_texture->getTexture()};
    this->m_sprite.setTextureRect(rect);
}

void arc::SFMLSprite::destroyEntity() {}

/**
 * Draw the sprite in the given window
 * @param window The window to draw the sprite in.
 */
void arc::SFMLSprite::drawEntity(__attribute__((unused))IWindow &window)
{
    sf::Vector2f vector = sf::Vector2f{static_cast<float>(this->entityPosition.getVectorX()),
        static_cast<float>(this->entityPosition.getVectorY())};
    SFMLWindow *sfml_window = dynamic_cast<SFMLWindow *>(&window);

    this->m_sprite.setPosition(vector);
    if (sfml_window == nullptr)
        throw;
    sfml_window->GetWindow().draw(this->m_sprite);
}
