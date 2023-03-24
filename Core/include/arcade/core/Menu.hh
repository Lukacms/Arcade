/*
** EPITECH PROJECT, 2023
** core
** File description:
** Menu
*/

#pragma once

#include <arcade/interfaces/IWindow.hh>

namespace arc
{
    /**
     * to display menu and make actions from it
     * all events are handled by the Core
     */
    class Menu
    {
        public:
            Menu() = default;
            Menu(Menu const &to_copy) = default;
            Menu(Menu &&to_move) = default;
            ~Menu() = default;
            Menu &operator=(Menu const &to_copy) = default;
            Menu &operator=(Menu &&to_move) = default;

            // class methods
            // to display
            void display(IWindow &window) const;

        private:
    };
} // namespace arc
