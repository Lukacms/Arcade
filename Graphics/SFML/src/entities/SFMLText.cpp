/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLText
*/

#include <arcade/interfaces/IEntity.hh>
#include <SFML/entities/SFMLText.hh>
#include <SFML/SFMLWindow.hh>
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
void arc::SFMLText::drawEntity(IWindow &window)
{
    sf::Vector2f vector = sf::Vector2f{this->entityPosition.getVectorX(), this->entityPosition.getVectorY()};
    SFMLWindow *sfml_window = dynamic_cast<SFMLWindow *>(&window);

    this->m_text.setPosition(vector);
    if (sfml_window == nullptr)
        throw;
    sfml_window->GetWindow().draw(this->m_text);
}

void arc::SFMLText::setFont(sf::Font &font)
{
    this->m_text.setFont(font);
}
