/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IText
*/

#pragma once

#include <arcade/Geometry.hh>
#include <arcade/interfaces/IWindow.hh>
#include <string>

namespace arc
{

    class IText
    {
        public:
            IText() = default;
            IText(IText &&) = delete;
            IText(const IText &) = default;
            virtual ~IText() = default;

            IText &operator=(const IText &) = default;
            IText &operator=(IText &&) = delete;

            virtual void setText(std::string str) = 0;
            virtual void setFont(const std::string &font) = 0;
            virtual void setTextColor(int red, int green, int blue) = 0;
            virtual void setTextPosition(int pos_x, int pos_y) = 0;
            virtual void drawText(IWindow &window) = 0;
            [[nodiscard]] virtual IText &getText() = 0;
    };
} // namespace arc
