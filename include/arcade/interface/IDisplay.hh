/*
** EPITECH PROJECT, 2023
** display
** File description:
** display
*/

#pragma once

#include <arcade/enum/EventEnum.hh>
#include <arcade/interface/IWindow.hh>

class IDisplay
{
    public:
        virtual ~IDisplay() = default;
        virtual IWindow &GetWindow() = 0;
        virtual bool IsDisplaySwitch() = 0;
        virtual bool IsGameSwitch() = 0;
        virtual Event GetEvent() = 0;
};
