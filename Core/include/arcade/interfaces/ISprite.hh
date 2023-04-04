/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ISprite
*/

#pragma once

#include <string>
#include <arcade/Geometry.hh>
#include <arcade/interfaces/IWindow.hh>

namespace arc {

    struct Color {
        int red;
        int green;
        int blue;
    };

    class ISprite {
        public:
            ISprite() = default;
            ISprite(ISprite &&) = delete;
            ISprite(const ISprite &) = default;
            virtual ~ISprite() = default;

            ISprite &operator=(const ISprite&) = default;
            ISprite &operator=(ISprite &&) = delete;

            virtual void setSpriteColor(int red, int green, int blue) = 0;
            virtual void moveSpritePosition(int pos_x, int pos_y) = 0;
            virtual void setSpritePosition(int pos_x, int pos_y) = 0;
            virtual void drawSprite(IWindow &window) = 0;
            [[nodiscard]] virtual ISprite &getSprite() = 0;
    };
}
