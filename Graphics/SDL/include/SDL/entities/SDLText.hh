/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLText
*/

#pragma once

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <arcade/interfaces/AText.hh>

namespace arc {

    class SDLText : public AText {
        public:
            SDLText() = default;
            SDLText(const SDLText&) = default;
            SDLText(SDLText &&) = delete;
            ~SDLText() = default;
    
            SDLText &operator=(const SDLText&) = default;
            SDLText &operator=(SDLText &&);

            void destroyText() final;
            void drawText(IWindow &window) final;
            [[nodiscard]] IText &getText() final;

        private:
            TTF_Font *m_font;
    };
}