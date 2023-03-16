/*
** EPITECH PROJECT, 2023
** src
** File description:
** SFMLWindow
*/

#include "SFML/SFMLWindow.hh"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <functional>
#include <memory>

SFMLWindow::SFMLWindow(unsigned int x_coord, unsigned int y_coord, const std::string &name_window)
    : m_window{sf::VideoMode{x_coord, y_coord}, name_window}
{
}

[[nodiscard]] const sf::RenderWindow &SFMLWindow::GetWindow()
{
    return m_window;
}

void SFMLWindow::OpenWindow()
{
    m_window.display();
}

void SFMLWindow::CloseWindow()
{
    m_window.close();
}

void SFMLWindow::CreateWindow(unsigned int x_coord, unsigned int y_coord) {}

void SFMLWindow::UpdateWindow() {}
