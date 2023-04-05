/*
** EPITECH PROJECT, 2023
** src
** File description:
** sdl
*/

#include <SDL/SDLDisplay.hh>
#include <memory>

extern "C" {

std::unique_ptr<arc::IDisplay> entryPoint()
{ // NOLINT
    std::unique_ptr<arc::SDLDisplay> display = std::make_unique<arc::SDLDisplay>();
    return display;
}
}