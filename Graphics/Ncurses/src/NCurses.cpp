/*
** EPITECH PROJECT, 2023
** src
** File description:
** NCurses
*/

#include <arcade/interfaces/IDisplay.hh>
#include <memory>
#include <ncurses/NCursesDisplay.hh>

extern "C" {

std::unique_ptr<arc::IDisplay> entryPoint()
{ // NOLINT
    std::unique_ptr<arc::IDisplay> display = std::make_unique<arc::NCursesDisplay>();
    return display;
}
}
