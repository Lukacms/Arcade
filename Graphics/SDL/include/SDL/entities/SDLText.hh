/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLText
*/

#pragma once

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IText.hh>
#include <string>

namespace arc
{

    class SDLText : public IText
    {
        public:
            SDLText() = default;
            SDLText(const SDLText &) = default;
            SDLText(SDLText &&) = delete;
            ~SDLText() override;

            SDLText &operator=(const SDLText &) = default;
            SDLText &operator=(SDLText &&) = delete;

            void setText(std::string str) final;
            void setFont(const std::string &font) final;
            void setTextColor(int red, int green, int blue) final;
            void setTextPosition(int pos_x, int pos_y) final;
            void drawText(IWindow &window) final;
            [[nodiscard]] IText &getText() final;

        private:
            std::string m_text;
            TTF_Font *m_font;
            arc::Color m_color{0, 0, 0};
            int pos_x;
            int pos_y;
    };
} // namespace arc