/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLSprite
*/

#pragma once

#include <SDL2/SDL_rect.h>
#include <arcade/interfaces/ASprite.hh>
#include <SFML/Graphics/RectangleShape.hpp>
#include <string>

namespace arc {

    class SDLSprite : public ASprite {

        public:
            SDLSprite();
            SDLSprite(const SDLSprite&);
            ~SDLSprite() override;

            SDLSprite &operator=(const SDLSprite&);

            void createSprite(const std::string &str);
            void createSprite(ISprite &sprite) final;
            void destroySprite() final;
            void drawSprite(IWindow &window) final;

        private:
            SDL_Rect m_sprite;
    };

}