/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IText
*/

#pragma once

#include <string>
#include <arcade/Geometry.hh>
#include <arcade/interfaces/IWindow.hh>

namespace arc {

        class IText {
        public:
            IText() = default;
            IText(IText &&) = delete;
            IText(const IText &) = default;
            virtual ~IText() = 0;

            IText &operator=(const IText&) = default;
            IText &operator=(IText &&) = delete;

            virtual void createText(std::string str) = 0;
            [[nodiscard]] virtual IText &getText() = 0;
            virtual void destroyText() = 0;
            virtual void setPosition(arc::Vector vector) = 0;
            virtual void setSize(int size) = 0;
            virtual void drawText(IWindow &window) = 0;
    };
}
