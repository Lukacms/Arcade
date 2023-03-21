/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesText
*/

#pragma once

#include <arcade/interfaces/AText.hh>
#include <arcade/interfaces/IWindow.hh>

namespace arc {

    class NCursesText : public AText {
        public:
            NCursesText() = default;
            NCursesText(const NCursesText&) = default;
            NCursesText(NCursesText &&) = delete;
            ~NCursesText() override = default;
    
            NCursesText &operator=(const NCursesText&) = default;
            NCursesText &operator=(NCursesText &&);

            void destroyText() final;
            void drawText(IWindow &window) final;
            [[nodiscard]] IText &getText() final;
    };
}
