/*
** EPITECH PROJECT, 2023
** core
** File description:
** Menu
*/

#pragma once

namespace arc
{
    /**
     * to display menu and make actions from it
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

        private:
    };
} // namespace arc
