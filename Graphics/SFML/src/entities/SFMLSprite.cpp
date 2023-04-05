/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLSprite
*/

#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/SFMLWindow.hh>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/entities/SFMLSprite.hh>
#include <arcade/RuntimeExecption.hh>

/* Constructor && Destructor */

/* Methods */

void arc::SFMLSprite::setSpritePosition(int pos_x, int pos_y)
{
    this->m_sprite.setPosition(pos_x * 40, pos_y * 30);
}

void arc::SFMLSprite::moveSpritePosition(int pos_x, int pos_y)
{
    this->m_sprite.move(pos_x, pos_y);
}

void arc::SFMLSprite::setSpriteColor(int red, int green, int blue)
{
    sf::Color color{static_cast<sf::Uint8>(red), static_cast<sf::Uint8>(green),
                    static_cast<sf::Uint8>(blue)};
    this->m_sprite.setFillColor(color);
}

void arc::SFMLSprite::drawSprite(IWindow &window)
{
    SFMLWindow *nwin = dynamic_cast<SFMLWindow *>(&window);

    if (nwin == nullptr)
        throw arc::RuntimeExecption{"ERROR"};
    this->m_sprite.setSize(sf::Vector2f{40, 30});
    nwin->GetWindow().draw(this->m_sprite);
}

arc::ISprite &arc::SFMLSprite::getSprite()
{
    return *this;
}
