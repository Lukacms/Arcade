/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesText
*/

#include <ncurses/NCursesWindow.hh>
#include <ncurses/entities/NCursesText.hh>

/* Constructor && Destructor */

/* Methods */

void arc::NCursesText::setText(std::string str)
{
    this->m_text = str;
}

void arc::NCursesText::setFont(__attribute__((unused)) const std::string &font) {}

void arc::NCursesText::setTextColor(int red, int green, int blue)
{
    this->m_color.red = red;
    this->m_color.green = green;
    this->m_color.blue = blue;
}

void arc::NCursesText::setTextPosition(int pos_x, int pos_y)
{
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

void arc::NCursesText::drawText(IWindow &window)
{
    NCursesWindow *nwin = dynamic_cast<NCursesWindow *>(&window);

    if (nwin == nullptr)
        throw;
    mvwprintw(nwin->GetWindow(), this->pos_x, this->pos_y, "%s", this->m_text.c_str());
}

arc::IText &arc::NCursesText::getText()
{
    return *this;
}
