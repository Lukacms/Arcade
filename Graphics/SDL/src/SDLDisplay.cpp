/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLDisplay
*/

#include <SDL/SDLDisplay.hh>
#include <SDL/SDLWindow.hh>
#include <SDL/entities/SDLSprite.hh>
#include <SDL/entities/SDLText.hh>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_ttf.h>
#include <arcade/enum/EventEnum.hh>
#include <iostream>
#include <memory>
#include <unordered_map>

/* Constructor && Destructor */

arc::SDLDisplay::SDLDisplay()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    this->m_window = std::make_unique<arc::SDLWindow>(800, 600, "Arcade");
}

/* Methods */

arc::Event arc::SDLDisplay::GetEvent()
{
    std::unordered_map<int, arc::Event> events = {{SDLK_UP, arc::Event::UP},
                                                  {SDLK_DOWN, arc::Event::DOWN},
                                                  {SDLK_LEFT, arc::Event::LEFT},
                                                  {SDLK_RIGHT, arc::Event::RIGHT},
                                                  {SDLK_ESCAPE, arc::Event::QUIT},
                                                  {SDLK_RETURN, arc::Event::ENTER},
                                                  {SDLK_F1, arc::Event::CHANGE_GAME_L},
                                                  {SDLK_F2, arc::Event::CHANGE_GAME_R},
                                                  {SDLK_F3, arc::Event::CHANGE_LIB_L},
                                                  {SDLK_F4, arc::Event::CHANGE_LIB_R},
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
                                                  {'q', arc::Event::BACK_MENU},
                                                  {SDLK_BACKSPACE, arc::Event::BACKSPACE}};
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type != SDL_KEYDOWN)
            return arc::Event::NONE;
        if (event.type == SDL_QUIT)
            return arc::Event::QUIT;
        for (auto iterator : events) {
            if (event.key.keysym.sym == iterator.first)
                return iterator.second;
        }
    }
    return arc::Event::NONE;
}

std::unique_ptr<arc::ISprite> arc::SDLDisplay::createSprite()
{
    return std::make_unique<arc::SDLSprite>();
}

std::unique_ptr<arc::IText> arc::SDLDisplay::createText()
{
    return std::make_unique<arc::SDLText>();
}