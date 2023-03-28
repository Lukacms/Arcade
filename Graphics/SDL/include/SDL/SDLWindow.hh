/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLWindow
*/

#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <arcade/interfaces/IWindow.hh>
#include <string>
#include <SDL2/SDL.h>

namespace arc
{
    class SDLWindow : public IWindow
    {
        public:
            SDLWindow() = default;
            SDLWindow(unsigned int x_coord, unsigned int y_coord, const std::string &name_window);
            ~SDLWindow() override;

            void OpenWindow() final;
            void CloseWindow() final;
            void CreateWindow(unsigned int x_coord, unsigned int y_coord) final;
            void UpdateWindow() final;
            [[nodiscard]] SDL_Renderer *GetRenderer();
            [[nodiscard]] SDL_Window *GetWindow();

        private:
            SDL_Window *m_window = nullptr;
            SDL_Renderer *m_renderer = nullptr;
    };
}