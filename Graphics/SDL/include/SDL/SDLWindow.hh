/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLWindow
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <arcade/interfaces/IWindow.hh>
#include <string>

namespace arc
{
    constexpr const int BACKSPACE = 127;

    class SDLWindow : public IWindow
    {
        public:
            SDLWindow() = default;
            SDLWindow(unsigned int x_coord, unsigned int y_coord, const std::string &name_window);
            ~SDLWindow() override;

            void OpenWindow() final = 0;
            void CloseWindow() final = 0;
            void CreateWindow(unsigned int x_coord, unsigned int y_coord) final = 0;
            void UpdateWindow() final = 0;
            [[nodiscard]] SDL_Renderer *GetRenderer();
            [[nodiscard]] SDL_Window *GetWindow();

        private:
            SDL_Window *m_window = nullptr;
            SDL_Renderer *m_renderer = nullptr;
    };
} // namespace arc