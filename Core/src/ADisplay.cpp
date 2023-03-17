/*
** EPITECH PROJECT, 2023
** src
** File description:
** ADisplay
*/

#include <arcade/interfaces/IWindow.hh>
#include <arcade/interfaces/ADisplay.hh>
#include <functional>

[[nodiscard]] std::reference_wrapper<arc::IWindow> arc::ADisplay::GetWindow()
{
    return std::ref(m_window->GetWindow());
}

[[nodiscard]] bool arc::ADisplay::IsDisplaySwitch()
{
    return m_is_display_switch;
}

[[nodiscard]] bool arc::ADisplay::IsGameSwitch()
{
    return m_is_game_switch;
}
