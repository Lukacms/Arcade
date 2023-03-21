/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AText
*/

#include <arcade/interfaces/AText.hh>

/* Constructor && Destructor */

/* Methods */

void arc::AText::createText(std::string str)
{
    this->m_text = str;
}

void arc::AText::setPosition(arc::Vector vector)
{
    this->m_position = vector;
}

void arc::AText::setSize(int size)
{
    this->m_size = size;
}
