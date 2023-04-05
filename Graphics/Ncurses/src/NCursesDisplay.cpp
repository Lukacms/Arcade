/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesDisplay
*/

#include <arcade/Opts.hh>
#include <arcade/enum/EventEnum.hh>
#include <arcade/interfaces/ISprite.hh>
#include <curses.h>
#include <iostream>
#include <map>
#include <memory>
#include <ncurses.h>
#include <ncurses/NCursesDisplay.hh>
#include <ncurses/NCursesWindow.hh>
#include <ncurses/entities/NCursesSprite.hh>
#include <ncurses/entities/NCursesText.hh>
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
                                                  {27, arc::Event::QUIT},
                                                  {KEY_BACKSPACE, arc::Event::BACKSPACE},
                                                  {'\n', arc::Event::ENTER},
                                                  {KEY_F(1), arc::Event::CHANGE_GAME_L},
                                                  {KEY_F(2), arc::Event::CHANGE_GAME_R},
                                                  {KEY_F(3), arc::Event::CHANGE_LIB_L},
                                                  {KEY_F(4), arc::Event::CHANGE_LIB_R},
                                                  {'r', arc::Event::RESTART},
                                                  {'a', arc::Event::A},
                                                  {'b', arc::Event::B},
                                                  {'c', arc::Event::C},
                                                  {'d', arc::Event::D},
                                                  {'e', arc::Event::E},
                                                  {'f', arc::Event::F},
                                                  {'g', arc::Event::G},
                                                  {'h', arc::Event::H},
                                                  {'i', arc::Event::I},
                                                  {'j', arc::Event::J},
                                                  {'k', arc::Event::K},
                                                  {'l', arc::Event::L},
                                                  {'m', arc::Event::M},
                                                  {'n', arc::Event::N},
                                                  {'o', arc::Event::O},
                                                  {'p', arc::Event::P},
                                                  {'r', arc::Event::R},
                                                  {'s', arc::Event::S},
                                                  {'t', arc::Event::T},
                                                  {'u', arc::Event::U},
                                                  {'v', arc::Event::V},
                                                  {'w', arc::Event::W},
                                                  {'x', arc::Event::X},
                                                  {'y', arc::Event::Y},
                                                  {'z', arc::Event::Z},
                                                  {'q', arc::Event::BACK_MENU}};
    int event_key = 0;
    WINDOW *win;
    NCursesWindow *nwin = dynamic_cast<NCursesWindow *>(&this->GetWindow().get());

    if (nwin == nullptr)
        throw Opts{"error nwim dynamic_cast"};
    win = nwin->GetWindow();
    event_key = wgetch(win);
    for (auto iterator : events) {
        if (event_key == KEY_F(3))
            std::cout << "Debug NCurses->SFML\n";
        if (event_key == iterator.first)
            return iterator.second;
    }
    return arc::Event::NONE;
};

std::unique_ptr<arc::ISprite> arc::NCursesDisplay::createSprite()
{
    return std::make_unique<arc::NCursesSprite>('#');
}

std::unique_ptr<arc::IText> arc::NCursesDisplay::createText()
{
    return std::make_unique<arc::NCursesText>();
}