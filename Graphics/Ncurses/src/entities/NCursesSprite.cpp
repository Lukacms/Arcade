/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesSprite
*/

#include "arcade/interfaces/ISprite.hh"
#include <curses.h>
#include <ncurses/entities/NCursesSprite.hh>
#include <ncurses/NCursesWindow.hh>

/* Constructor && Destructor */

/* Methods */

void arc::NCursesSprite::setSpriteColor(int red, int green, int blue)
{
    this->m_color.red = red;
    this->m_color.green = green;
    this->m_color.blue = blue;
}

void arc::NCursesSprite::setSpritePosition(int pos_x, int pos_y)
{
    this->m_x = pos_x;
    this->m_y = pos_y;
}

void arc::NCursesSprite::moveSpritePosition(int pos_x, int pos_y)
{
    this->m_x += pos_x;
    this->m_y += pos_y;
}

void arc::NCursesSprite::drawSprite(IWindow &window)
{
    NCursesWindow *nwin = dynamic_cast<NCursesWindow *>(&window);

    if (nwin == nullptr)
        throw;
    mvwprintw(nwin->GetWindow(), this->m_x, this->m_y, "%c", this->m_sprite);
}

arc::ISprite &arc::NCursesSprite::getSprite()
{
    return *this;
}
