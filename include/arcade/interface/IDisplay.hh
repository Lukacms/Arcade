/*
** EPITECH PROJECT, 2023
** display
** File description:
** display
*/

#pragma once

#include "arcade/enum/EventEnum.hh"
#include "arcade/interface/IWindow.hh"

class IDisplay
{
    public:
        IDisplay() = default;
        ~IDisplay() = default;

    private:
};

namespace Arc
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
            [[nodiscard]] virtual Arc::IWindow &GetWindow() = 0;
            [[nodiscard]] virtual bool IsDisplaySwitch() = 0;
            [[nodiscard]] virtual bool IsGameSwitch() = 0;
            [[nodiscard]] virtual Arc::Event GetEvent() = 0;
    };
} // namespace Arc
