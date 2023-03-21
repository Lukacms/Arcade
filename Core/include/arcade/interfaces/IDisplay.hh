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
            [[nodiscard]] virtual std::reference_wrapper<arc::IWindow> GetWindow() = 0;
            [[nodiscard]] virtual arc::Event GetEvent() = 0;
    };
} // namespace arc
