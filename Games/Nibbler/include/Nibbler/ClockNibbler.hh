/*
** EPITECH PROJECT, 2023
** Nibbler
** File description:
** ClockNibbler
*/

#pragma once

#include <chrono>

constexpr double CLOCK_UPDATE_TIME = 20.00;

class NibblerClock
{
    public:
        NibblerClock() = default;
        NibblerClock(NibblerClock const &to_copy) = default;
        NibblerClock(NibblerClock &&to_move) = default;
        ~NibblerClock() = default;
        NibblerClock &operator=(NibblerClock const &to_copy) = default;
        NibblerClock &operator=(NibblerClock &&to_move) = default;

        [[nodiscard]] std::chrono::duration<double> getElapsedTime();
        [[nodiscard]] double getElapsedTimeInS();
        void reset();

    private:
        std::chrono::time_point<std::chrono::steady_clock> start{std::chrono::steady_clock::now()};
        std::chrono::time_point<std::chrono::steady_clock> updated{
            std::chrono::steady_clock::now()};
};
