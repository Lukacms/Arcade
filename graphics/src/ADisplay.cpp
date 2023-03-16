/*
** EPITECH PROJECT, 2023
** src
** File description:
** ADisplay
*/

#include "graphics/include/ADisplay.hh"
#include <functional>

[[nodiscard]] arc::IWindow &arc::ADisplay::GetWindow()
{
    return &m_window.get();
}

[[nodiscard]] bool arc::ADisplay::IsDisplaySwitch()
{
    return m_is_display_switch;
}

[[nodiscard]] bool arc::ADisplay::IsGameSwitch()
{
    return m_is_game_switch;
}
