/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLWindow
*/

#include <SDL/SDLWindow.hh>
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

/* Constructor && Destructor */

arc::SDLWindow::SDLWindow(unsigned int x_coord, unsigned int y_coord, const std::string &name_window)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw;
    this->m_window = SDL_CreateWindow(name_window.c_str(), SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, x_coord, y_coord, SDL_WINDOW_SHOWN);
    if (this->m_window == nullptr)
        throw;
    this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED);
    if (this->m_renderer == nullptr)
        throw;
}

arc::SDLWindow::~SDLWindow()
{
    if (this->m_window != nullptr)
        SDL_DestroyWindow(this->m_window);
    if (this->m_renderer!= nullptr)
        SDL_DestroyRenderer(this->m_renderer);
    SDL_Quit();
}

/* Methods */

void arc::SDLWindow::OpenWindow()
{
    SDL_ShowWindow(this->m_window);
    SDL_RenderPresent(m_renderer);
}

void arc::SDLWindow::CloseWindow()
{
    if (this->m_window!= nullptr)
        SDL_DestroyWindow(this->m_window);
    if (this->m_renderer!= nullptr)
        SDL_DestroyRenderer(this->m_renderer);
}

void arc::SDLWindow::UpdateWindow()
{
    SDL_RenderClear(this->m_renderer);
}

void arc::SDLWindow::CreateWindow(unsigned int x_coord, unsigned int y_coord)
{
    this->CloseWindow();
    this->m_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, x_coord, y_coord, SDL_WINDOW_SHOWN);
    this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Window *arc::SDLWindow::GetWindow()
{
    return this->m_window;
}

SDL_Renderer *arc::SDLWindow::GetRenderer()
{
    return this->m_renderer;
}