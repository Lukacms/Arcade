/*
** EPITECH PROJECT, 2023
** display
** File description:
** display
*/

#pragma once

#include "core/arcade/enum/EventEnum.hh"
#include "core/arcade/interfaces/IWindow.hh"

namespace arc
{
    class IDisplay
    {
        public:
            IDisplay() = delete;
            IDisplay(IDisplay const &to_copy) = delete;
            IDisplay(IDisplay &&to_move) = delete;
            IDisplay &operator=(IDisplay const &to_copy) = delete;
            IDisplay &operator=(IDisplay const &&to_move) = delete;
            virtual ~IDisplay() = default;
            [[nodiscard]] virtual arc::IWindow &GetWindow() = 0;
            [[nodiscard]] virtual bool IsDisplaySwitch() = 0;
            [[nodiscard]] virtual bool IsGameSwitch() = 0;
            [[nodiscard]] virtual arc::Event GetEvent() = 0;
    };
} // namespace arc