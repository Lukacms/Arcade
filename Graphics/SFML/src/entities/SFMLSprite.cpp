/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLSprite
*/

#include "SFML/SFMLWindow.hh"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/entities/SFMLSprite.hh>

/* Constructor && Destructor */

/* Methods */

void arc::SFMLSprite::createSprite(const std::string &str) {}

void arc::SFMLSprite::createSprite(ISprite &sprite) {}

void arc::SFMLSprite::destroySprite()
{
    this->m_sprite.setSize(sf::Vector2f{0, 0});
    this->m_sprite.setFillColor(sf::Color::Black);
}

void arc::SFMLSprite::drawSprite(IWindow &window)
{
    sf::Vector2f pos{static_cast<float>(this->m_position.getVectorX()),
        static_cast<float>(this->m_position.getVectorY())};
    SFMLWindow *nwin = dynamic_cast<SFMLWindow *>(&window);

    if (nwin == nullptr)
        throw;
    this->m_sprite.setPosition(pos);
    nwin->GetWindow().draw(this->m_sprite);
}