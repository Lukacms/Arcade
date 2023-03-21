/*
** EPITECH PROJECT, 2023
** display
** File description:
** display
*/

#pragma once

#include <arcade/enum/EventEnum.hh>
#include <arcade/interfaces/IWindow.hh>
#include <functional>

namespace arc
{
    class IDisplay
    {
        public:
            virtual ~IDisplay() = default;
            IDisplay() = default;
            IDisplay(IDisplay const &to_copy) = default;
            IDisplay(IDisplay &&to_move) = default;
            IDisplay &operator=(IDisplay const &to_copy) = default;
            IDisplay &operator=(IDisplay &&to_move) = default;
            [[nodiscard]] virtual std::reference_wrapper<arc::IWindow> GetWindow() = 0;
            [[nodiscard]] virtual arc::Event GetEvent() = 0;
    };
} // namespace arc
