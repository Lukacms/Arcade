/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLText
*/

#include <SFML/Graphics/Text.hpp>
#include <SFML/SFMLWindow.hh>
#include <SFML/entities/SFMLText.hh>

/* Constructor && Destructor */

/* Methods */

void arc::SFMLText::destroyText() {}

void arc::SFMLText::drawText(arc::IWindow &window)
{
    SFMLWindow *nwin = dynamic_cast<SFMLWindow *>(&window);
    sf::Text text;

    if (nwin == nullptr)
        throw;
    text.setString(this->m_text);
    text.setFont(this->m_font);
    text.setCharacterSize(this->m_size);
    text.setFillColor(sf::Color::White);
    nwin->GetWindow().draw(text);
}

arc::IText &arc::SFMLText::getText()
{
    return *this;
}