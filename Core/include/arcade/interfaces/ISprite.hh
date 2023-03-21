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
            virtual ~ISprite() = 0;

            ISprite &operator=(const ISprite&) = default;
            ISprite &operator=(ISprite &&) = delete;

            virtual void createSprite(std::string str) = 0;
            virtual void createSprite(ISprite &) = 0;
            [[nodiscard]] virtual ISprite &getSprite() = 0;
            virtual void destroySprite() = 0;
            virtual void moveSprite(arc::Vector vector) = 0;
            virtual void setPosition(arc::Vector vector) = 0;
            virtual void setSize(arc::Vector vector) = 0;
            virtual void setRectangle(arc::Rect rectangle) = 0;
            virtual void setColor(int red, int green, int blue) = 0;
            virtual void drawSprite(IWindow &window) = 0;
    };
}
