/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesDisplay
*/

#include <memory>
#include <ncurses/NCursesWindow.hh>
#include <arcade/enum/EventEnum.hh>
#include <curses.h>
#include <map>
#include <ncurses/NCursesDisplay.hh>
#include <unordered_map>
#include <exception>

/* Constructor && Destructor */

arc::NCursesDisplay::NCursesDisplay()
{
    std::unique_ptr<NCursesWindow> window = std::make_unique<NCursesWindow>(20, 20);

    this->m_window = std::move(window);
}

/* Methods */

arc::Event arc::NCursesDisplay::GetEvent()
{
    std::unordered_map<int, arc::Event> events = {
        {KEY_UP, arc::Event::UP}, {KEY_DOWN, arc::Event::DOWN},
        {KEY_LEFT, arc::Event::LEFT}, {KEY_RIGHT, arc::Event::RIGHT},
        {KEY_EXIT, arc::Event::QUIT}, {KEY_ENTER, arc::Event::ENTER},
        {KEY_F(1), arc::Event::CHANGE_GAME_L}, {KEY_F(2), arc::Event::CHANGE_GAME_R},
        {KEY_F(3), arc::Event::CHANGE_LIB_L}, {KEY_F(4), arc::Event::CHANGE_LIB_R}
    };
    int event_key = 0;
    WINDOW *win;
    NCursesWindow *nwin = dynamic_cast<NCursesWindow *>(&this->GetWindow().get());

    if (nwin == nullptr)
        throw;
    win = nwin->GetWindow();
    event_key = wgetch(win);
    for (auto iterator : events) {
        if (event_key == iterator.first)
            return iterator.second;
    }
    return arc::Event::NONE;
};