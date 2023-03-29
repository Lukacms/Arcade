/*
** EPITECH PROJECT, 2023
** core
** File description:
** CoreClock
*/

#pragma once

#include <chrono>

namespace arc
{
    class CoreClock
    {
        public:
            // basic methods
            CoreClock() = default;
            CoreClock(CoreClock const &to_copy) = default;
            CoreClock(CoreClock &&to_move) = default;
            ~CoreClock() = default;
            CoreClock &operator=(CoreClock const &to_copy) = default;
            CoreClock &operator=(CoreClock &&to_move) = default;

            // function methods
            [[nodiscard]] std::chrono::duration<double> getElapsedTime();
            void reset();

        private:
            // NOTE really don't need to do getters / setters for thoses
            std::chrono::time_point<std::chrono::steady_clock> start{
                std::chrono::steady_clock::now()};
            std::chrono::time_point<std::chrono::steady_clock> updated{
                std::chrono::steady_clock::now()};
    };
} // namespace arc
