/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesSprite
*/

#include <curses.h>
#include <ncurses/entities/NCursesSprite.hh>
#include <ncurses/NCursesWindow.hh>

/* Constructor && Destructor */

/* Methods */

void arc::NCursesSprite::createSprite(const std::string &str) {}

void arc::NCursesSprite::createSprite(ISprite &sprite) {}

void arc::NCursesSprite::destroySprite()
{
    this->m_sprite = '\0';
}

void arc::NCursesSprite::drawSprite(IWindow &window)
{
    NCursesWindow *nwin = dynamic_cast<NCursesWindow *>(&window);

    if (nwin == nullptr)
        throw;
    mvwprintw(nwin->GetWindow(), this->m_position.getVectorX(),
        this->m_position.getVectorY(), "%c", this->m_sprite);
}