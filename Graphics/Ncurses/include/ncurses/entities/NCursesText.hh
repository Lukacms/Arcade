/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesText
*/

#pragma once

#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IText.hh>
#include <arcade/interfaces/IWindow.hh>

namespace arc {

    class NCursesText : public IText {
        public:
            NCursesText() = default;
            NCursesText(const NCursesText&) = default;
            NCursesText(NCursesText &&) = delete;
            ~NCursesText() override = default;
    
            NCursesText &operator=(const NCursesText&) = default;
            NCursesText &operator=(NCursesText &&) = delete;

            void setText(std::string str) final;
            void setFont(const std::string &font) final;
            void setTextColor(int red, int green, int blue) final;
            void setTextPosition(int pos_x, int pos_y) final;
            void drawText(IWindow &window) final;
            [[nodiscard]] IText &getText() final;

        private:
            std::string m_text;
            arc::Color m_color;
            int pos_x;
            int pos_y;
    };
}
