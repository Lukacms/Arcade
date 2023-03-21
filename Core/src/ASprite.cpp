/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ASprite
*/

#include <arcade/interfaces/ASprite.hh>

/* Constructor && Destructor */

/* Methods */

void arc::ASprite::moveSprite(arc::Vector vector)
{
    this->m_position += vector;
}

void arc::ASprite::setPosition(arc::Vector vector)
{
    this->m_position = vector;
}

void arc::ASprite::setSize(arc::Vector vector)
{
    this->m_size = vector;
}

void arc::ASprite::setRectangle(arc::Rect rect)
{
    this->m_rectangle = rect;
}

void arc::ASprite::setColor(int red, int green, int blue)
{
    this->m_color.red = red;
    this->m_color.green = green;
    this->m_color.blue = blue;
}
