/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLDisplay
*/

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <arcade/enum/EventEnum.hh>
#include <SDL/SDLDisplay.hh>
#include <memory>
#include <unordered_map>
#include <SDL/SDLWindow.hh>

/* Constructor && Destructor */

arc::SDLDisplay::SDLDisplay()
{
    std::unique_ptr<SDLWindow> window = std::make_unique<SDLWindow>();

    this->m_window = std::make_unique<arc::SDLWindow>(800, 600, "Arcade");
}

/* Methods */

arc::Event arc::SDLDisplay::GetEvent()
{
    std::unordered_map<int, arc::Event>events = {
        {SDLK_UP, arc::Event::UP}, {SDLK_DOWN, arc::Event::DOWN},
        {SDLK_LEFT, arc::Event::LEFT}, {SDLK_RIGHT, arc::Event::RIGHT},
        {SDLK_ESCAPE, arc::Event::QUIT}, {SDLK_KP_ENTER, arc::Event::ENTER},
        {SDLK_F1, arc::Event::CHANGE_GAME_L}, {SDLK_F2, arc::Event::CHANGE_GAME_R},
        {SDLK_F3, arc::Event::CHANGE_LIB_L}, {SDLK_F4, arc::Event::CHANGE_LIB_R}
    };
    SDL_Event event;

    SDL_PollEvent(&event);
    if (event.type != SDL_KEYDOWN)
        return arc::Event::NONE;
    if (event.type == SDL_QUIT)
        return arc::Event::QUIT;
    for (auto iterator : events) {
        if (event.key.keysym.sym == iterator.first)
            return iterator.second;
    }
    return arc::Event::NONE;
}