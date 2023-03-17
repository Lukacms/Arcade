/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLText
*/

#include <arcade/interfaces/IEntity.hh>
#include <SFML/entities/SFMLText.hh>
#include <string>

/* Constructor && Destructor */

/* Methods */

/**
 * Create an sf::Text with the given text.
 * @param str The string that represents the text.
 */
void arc::SFMLText::createEntity(std::string str)
{
    this->m_text.setString(str);
}

void arc::SFMLText::createEntity(__attribute__((unused))  arc::IEntity &texture) {}

void arc::SFMLText::destroyEntity() {}

/**
 * Draw the text in the given window.
 * @param window The window in which to draw.
 */
void arc::SFMLText::drawEntity(__attribute__((unused)) IWindow &window)
{
    sf::Vector2f vector = sf::Vector2f{this->entityPosition.getVectorX(), this->entityPosition.getVectorY()};

    this->m_text.setPosition(vector);
    // Dynamic cast + vérif du dynamic cast + draw dans la window donné
}

void arc::SFMLText::setFont(sf::Font &font)
{
    this->m_text.setFont(font);
}
