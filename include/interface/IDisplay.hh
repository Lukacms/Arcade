/*
** EPITECH PROJECT, 2023
** display
** File description:
** display
*/

#pragma once

#include "window.hh"

class IDisplay
{
    public:
        virtual ~IDisplay() = default;
        virtual IWindow &GetWindow() = 0;
        virtual bool is_display_switch() = 0;
        virtual bool is_game_switch() = 0;
};
