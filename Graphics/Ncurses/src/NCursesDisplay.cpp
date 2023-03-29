/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesDisplay
*/

#include <arcade/interfaces/ISprite.hh>
#include <ncurses/entities/NCursesSprite.hh>
#include <ncurses/entities/NCursesText.hh>
#include <arcade/Opts.hh>
#include <memory>
#include <ncurses/NCursesWindow.hh>
#include <arcade/enum/EventEnum.hh>
#include <curses.h>
#include <map>
#include <ncurses.h>
#include <ncurses/NCursesDisplay.hh>
#include <unordered_map>

/* Constructor && Destructor */

arc::NCursesDisplay::NCursesDisplay()
{
    std::unique_ptr<NCursesWindow> window = std::make_unique<NCursesWindow>(20, 20);

    this->m_window = std::move(window);
}

/* Methods */

arc::Event arc::NCursesDisplay::GetEvent()
{
    std::unordered_map<int, arc::Event> events = {{KEY_UP, arc::Event::UP},
                                                  {KEY_DOWN, arc::Event::DOWN},
                                                  {KEY_LEFT, arc::Event::LEFT},
                                                  {KEY_RIGHT, arc::Event::RIGHT},
                                                  {KEY_EXIT, arc::Event::QUIT},
                                                  {KEY_ENTER, arc::Event::ENTER},
                                                  {KEY_F(1), arc::Event::CHANGE_GAME_L},
                                                  {KEY_F(2), arc::Event::CHANGE_GAME_R},
                                                  {KEY_F(3), arc::Event::CHANGE_LIB_L},
                                                  {KEY_F(4), arc::Event::CHANGE_LIB_R}};
    int event_key = 0;
    WINDOW *win;
    NCursesWindow *nwin = dynamic_cast<NCursesWindow *>(&this->GetWindow().get());

    if (nwin == nullptr)
        throw Opts{"error nwim dynamic_cast"};
    win = nwin->GetWindow();
    event_key = wgetch(win);
    for (auto iterator : events) {
        if (event_key == iterator.first)
            return iterator.second;
    }
    return arc::Event::NONE;
};

std::string arc::NCursesDisplay::GetUserName()
{
    int event_key{-1};
    WINDOW *win;
    NCursesWindow *nwin = dynamic_cast<NCursesWindow *>(&this->GetWindow().get());
    std::string name{};

    if (nwin == nullptr)
        throw Opts{"error nwim dynamic_cast"};
    win = nwin->GetWindow();
    if (!win)
        throw Opts{"error wim is null NCursesDisplay"};
    while (event_key != '\n') {
        event_key = wgetch(win);
        if (event_key == arc::BACKSPACE && !name.empty()) {
            name.pop_back();
            wclear(win);
            wprintw(win, "%s", name.c_str());
        }
        if (event_key >= 'a' && event_key <= 'z') {
            name.push_back(event_key);
            wclear(win);
            wprintw(win, "%s", name.c_str());
        }
    }
    if (name.empty())
        return std::string{"Arcade Sucks"};
    return name;
}

std::unique_ptr<arc::ISprite> arc::NCursesDisplay::createSprite()
{
    return std::make_unique<arc::NCursesSprite>('#');
}

std::unique_ptr<arc::IText> arc::NCursesDisplay::createText()
{
    return std::make_unique<arc::NCursesText>();
}