/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesDisplay
*/

#pragma once

#include <arcade/interfaces/IWindow.hh>
#include <arcade/interfaces/ADisplay.hh>
#include <functional>
#include <memory>

namespace arc
{
    class NCursesDisplay : public ADisplay
    {
        public:
            NCursesDisplay();
            NCursesDisplay(NCursesDisplay const &to_copy) = delete;
            NCursesDisplay(NCursesDisplay &&to_move) = delete;
            NCursesDisplay &operator=(NCursesDisplay const &to_copy) = delete;
            NCursesDisplay &operator=(NCursesDisplay const &&to_move) = delete;
            ~NCursesDisplay() override = default;
            std::unique_ptr<arc::ISprite> createSprite() override;
            std::unique_ptr<arc::IText> createText() override;

            [[nodiscard]] arc::Event GetEvent() final;
    };
} // namespace arc