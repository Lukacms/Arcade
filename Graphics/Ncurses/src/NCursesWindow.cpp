/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesWindow
*/

#include <arcade/RuntimeExecption.hh>
#include <curses.h>
#include <iostream>
#include <ncurses.h>
#include <ncurses/NCursesWindow.hh>

/* Constructor && Destructor */

arc::NCursesWindow::NCursesWindow(unsigned int x_coord, unsigned int y_coord)
{
    initscr();
    if (has_colors() == FALSE)
        throw arc::RuntimeExecption{"ERROR"};
    start_color();
    curs_set(0);
    this->m_window = newwin(y_coord * 2, x_coord * 4, 0, 0);
    if (this->m_window == nullptr)
        throw arc::RuntimeExecption{"ERROR"};
    keypad(this->m_window, true);
    nodelay(this->m_window, true);
}

arc::NCursesWindow::~NCursesWindow()
{
    delwin(this->m_window);
    endwin();
}

/* Methods */

void arc::NCursesWindow::OpenWindow() {}

void arc::NCursesWindow::CloseWindow()
{
    delwin(this->m_window);
}

void arc::NCursesWindow::CreateWindow(unsigned int x_coord, unsigned int y_coord)
{
    this->m_window = newwin(x_coord, y_coord, 0, 0);
    if (this->m_window == nullptr)
        throw arc::RuntimeExecption{"ERROR"};
    nodelay(this->m_window, true);
}

void arc::NCursesWindow::UpdateWindow()
{
    wclear(this->m_window);
}

WINDOW *arc::NCursesWindow::GetWindow()
{
    return this->m_window;
}
