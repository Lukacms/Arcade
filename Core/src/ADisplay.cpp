/*
** EPITECH PROJECT, 2023
** src
** File description:
** ADisplay
*/

#include <arcade/interfaces/ADisplay.hh>
#include <arcade/interfaces/IWindow.hh>
#include <functional>
#include <iostream>
#include <memory>

std::reference_wrapper<arc::IWindow> arc::ADisplay::GetWindow()
{
    std::reference_wrapper<arc::IWindow> window = std::ref(*m_window);
    return window;
}
