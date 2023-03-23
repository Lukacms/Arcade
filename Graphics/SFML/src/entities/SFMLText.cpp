/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLText
*/

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/SFMLWindow.hh>
#include <SFML/entities/SFMLText.hh>

/* Constructor && Destructor */

/* Methods */

void arc::SFMLText::setText(std::string str)
{
    this->m_text.setString(str);
}

void arc::SFMLText::setFont(const std::string &font)
{
    if (!this->m_font.loadFromFile(font))
        throw;
    this->m_text.setFont(this->m_font);
}

void arc::SFMLText::setTextColor(int red, int green, int blue)
{
    sf::Color color{static_cast<sf::Uint8>(red), static_cast<sf::Uint8>(green),
                    static_cast<sf::Uint8>(blue)};

    this->m_text.setFillColor(color);
}

void arc::SFMLText::setTextPosition(int pos_x, int pos_y)
{
    this->m_text.setPosition(pos_x, pos_y);
}

void arc::SFMLText::drawText(arc::IWindow &window)
{
    SFMLWindow *nwin = dynamic_cast<SFMLWindow *>(&window);
    sf::Text text;

    if (nwin == nullptr)
        throw;
    text.setFont(this->m_font);
    text.setFillColor(sf::Color::White);
    nwin->GetWindow().draw(text);
}

arc::IText &arc::SFMLText::getText()
{
    return *this;
}
