/*
** EPITECH PROJECT, 2023
** src
** File description:
** ADisplay
*/

#include <arcade/interfaces/ADisplay.hh>
#include <arcade/interfaces/IWindow.hh>
#include <functional>
#include <memory>

[[nodiscard]] std::reference_wrapper<arc::IWindow> arc::ADisplay::GetWindow()
{
    return std::reference_wrapper<arc::IWindow>{std::ref(*m_window)};
}
