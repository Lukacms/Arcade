/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLSprite
*/

#pragma once

#include <SDL2/SDL_rect.h>
#include <SFML/Graphics/RectangleShape.hpp>
#include <arcade/interfaces/ISprite.hh>
#include <string>

namespace arc
{

    class SDLSprite : public ISprite
    {

        public:
            SDLSprite();
            SDLSprite(const SDLSprite &);
            ~SDLSprite() override = default;

            SDLSprite &operator=(const SDLSprite &);

            void setSpriteColor(int red, int green, int blue) final;
            void moveSpritePosition(int pos_x, int pos_y) final;
            void setSpritePosition(int pos_x, int pos_y) final;
            void drawSprite(IWindow &window) final;
            [[nodiscard]] ISprite &getSprite() final;

        private:
            SDL_Rect m_sprite;
            arc::Color m_color = {0, 0, 0};
    };

} // namespace arc