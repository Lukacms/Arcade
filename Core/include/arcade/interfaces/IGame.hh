/*
** EPITECH PROJECT, 2023
** interfaces
** File description:
** IGame
*/

#pragma once

#include <arcade/enum/EventEnum.hh>
#include <arcade/interfaces/IDisplay.hh>
#include <arcade/interfaces/IWindow.hh>

namespace arc
{
    class IGame
    {
        public:
            IGame() = default;
            IGame(IGame const &to_copy) = default;
            IGame(IGame &&to_move) = default;
            virtual ~IGame() = default;
            IGame &operator=(IGame const &to_copy) = default;
            IGame &operator=(IGame &&to_move) = default;

            virtual void EventAnalisys(const arc::Event &event) = 0; // Analysis
            virtual void DisplayGame(IWindow &window) = 0;
            virtual void ResetGame() = 0;
            virtual void PlayGame() = 0;
            virtual void InitGame() = 0;
            virtual void SetSprite(arc::IDisplay &display) = 0;
            virtual void SetText(arc::IDisplay &display) = 0;
    };
} // namespace arc
