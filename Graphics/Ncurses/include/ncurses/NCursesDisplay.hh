/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesDisplay
*/

#pragma once

#include <arcade/interfaces/ADisplay.hh>

namespace arc
{

    class NCursesDisplay : public ADisplay {
        public:
            NCursesDisplay();
            NCursesDisplay(NCursesDisplay const &to_copy) = delete;
            NCursesDisplay(NCursesDisplay &&to_move) = delete;
            NCursesDisplay &operator=(NCursesDisplay const &to_copy) = delete;
            NCursesDisplay &operator=(NCursesDisplay const &&to_move) = delete;
            ~NCursesDisplay() override = default;

            [[nodiscard]] arc::Event GetEvent() final = 0;
    };
}