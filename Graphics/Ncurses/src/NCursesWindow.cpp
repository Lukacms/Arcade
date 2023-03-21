/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesWindow
*/

#include <curses.h>
#include <ncurses/NCursesWindow.hh>

/* Constructor && Destructor */

arc::NCursesWindow::NCursesWindow(unsigned int x_coord, unsigned int y_coord, const std::string &name)
{
    this->m_window = newwin(x_coord, y_coord, 0, 0);
    if (this->m_window == nullptr)
        throw;
}

/* Methods */

void arc::NCursesWindow::OpenWindow()
{
    initscr();
}

void arc::NCursesWindow::CloseWindow()
{
    endwin();
}

void arc::NCursesWindow::CreateWindow(unsigned int x_coord, unsigned int y_coord)
{
    this->m_window = newwin(x_coord, y_coord, 0, 0);
    if (this->m_window == nullptr)
        throw;
}

void arc::NCursesWindow::UpdateWindow()
{
    wrefresh(this->m_window);
}
