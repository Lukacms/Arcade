/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesText
*/

#include <ncurses/entities/NCursesText.hh>
#include <ncurses/NCursesWindow.hh>

/* Constructor && Destructor */

/* Methods */

void arc::NCursesText::destroyText()
{
    this->m_text = "";
}

void arc::NCursesText::drawText(IWindow &window)
{
    NCursesWindow *nwin = dynamic_cast<NCursesWindow *>(&window);

    if (nwin == nullptr)
        throw;
    mvwprintw(nwin->GetWindow(), this->m_position.getVectorX(),
        this->m_position.getVectorY(), "%s", this->m_text.c_str());
}

arc::IText &arc::NCursesText::getText()
{
    return *this;
}
