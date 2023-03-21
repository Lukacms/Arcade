/*
** EPITECH PROJECT, 2023
** interfaces
** File description:
** IGame
*/

#pragma once

#include <arcade/enum/EventEnum.hh>

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

            virtual void EventAnalisys(arc::Event) = 0;
            virtual void PlayGame() = 0;
            virtual void SaveGame() = 0;
            virtual void LoadGame() = 0;
            virtual void ResetGame() = 0;
            virtual void IsExit() = 0;
            virtual void InitGame() = 0;
    };
} // namespace arc
