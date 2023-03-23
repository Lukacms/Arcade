/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLSprite
*/

#include <SFML/Config.hpp>
#include <SFML/SFMLWindow.hh>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/entities/SFMLSprite.hh>

/* Constructor && Destructor */

/* Methods */

void arc::SFMLSprite::setSpritePosition(int pos_x, int pos_y)
{
    this->m_sprite.setPosition(pos_x, pos_y);
}

void arc::SFMLSprite::moveSpritePosition(int pos_x, int pos_y)
{
    this->m_sprite.move(pos_x, pos_y);
}

void arc::SFMLSprite::setSpriteColor(int red, int green, int blue)
{
    sf::Color color{static_cast<sf::Uint8>(red), static_cast<sf::Uint8>(green), static_cast<sf::Uint8>(blue)};
    this->m_sprite.setFillColor(color);
}

void arc::SFMLSprite::drawSprite(IWindow &window)
{
    SFMLWindow *nwin = dynamic_cast<SFMLWindow *>(&window);

    if (nwin == nullptr)
        throw;
    nwin->GetWindow().draw(this->m_sprite);
}

arc::ISprite &arc::SFMLSprite::getSprite()
{
    return *this;
}
