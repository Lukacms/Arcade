/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core
*/

#pragma once

namespace arc
{
    class Core
    {
        public:
            Core() = default;
            Core(Core const &to_copy) = default;
            Core(Core &&to_move) = default;

            ~Core() = default;

            Core &operator=(Core const &to_copy) = default;

        private:
    };
} // namespace arc
