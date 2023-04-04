/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesSprite
*/

#include "arcade/interfaces/ISprite.hh"
#include <curses.h>
#include <ncurses/NCursesWindow.hh>
#include <ncurses/entities/NCursesSprite.hh>
#include <cmath>

/* Constructor && Destructor */

arc::NCursesSprite::NCursesSprite(char sprite) : m_sprite(sprite) {}

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
    float color_id = round((this->m_color.red + this->m_color.green + this->m_color.blue) / 3);

    if (nwin == nullptr)
        throw;
    init_color(color_id, this->m_color.red * 1000 / 255, this->m_color.green * 1000 / 255, this->m_color.blue * 1000 / 255);
    init_pair(color_id, color_id, color_id);
    wattron(nwin->GetWindow(), COLOR_PAIR(color_id));
    for (int offset_y = 0; offset_y < 2; offset_y += 1) {
        for (int offset_x = 0; offset_x < 4; offset_x += 1) {
            mvwprintw(nwin->GetWindow(), (this->m_y * 2) + offset_y, (this->m_x * 4) + offset_x, "%c", this->m_sprite);
        }
    }
    wattroff(nwin->GetWindow(), COLOR_PAIR(1));
}

arc::ISprite &arc::NCursesSprite::getSprite()
{
    return *this;
}
