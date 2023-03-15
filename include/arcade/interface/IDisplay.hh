/*
** EPITECH PROJECT, 2023
** display
** File description:
** display
*/

#pragma once

#include "arcade/enum/EventEnum.hh"
#include "arcade/interface/IWindow.hh"

namespace Arc
{
    class IDisplay
    {
        public:
            virtual ~IDisplay() = default;
            virtual Arc::IWindow &GetWindow() = 0;
            virtual bool IsDisplaySwitch() = 0;
            virtual bool IsGameSwitch() = 0;
    };
} // namespace Arc
