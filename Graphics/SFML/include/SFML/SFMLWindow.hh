/*
** EPITECH PROJECT, 2023
** SFML
** File description:
** SFMLWindow
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <arcade/interfaces/IWindow.hh>

class SFMLWindow : public arc::IWindow
{
    public:
        SFMLWindow();
        SFMLWindow(unsigned int x_coord, unsigned int y_coord, const std::string &name_window);
        SFMLWindow(SFMLWindow const &to_copy) = delete;
        SFMLWindow &operator=(SFMLWindow const &to_copy) = delete;
        SFMLWindow &operator=(SFMLWindow const &&to_move) = delete;
        SFMLWindow(SFMLWindow &&to_move) = delete;
        ~SFMLWindow() override = default;
        void OpenWindow() final;
        void CloseWindow() final;
        void CreateWindow(unsigned int x_coord, unsigned int y_coord) final;
        void UpdateWindow() final;
        [[nodiscard]] sf::RenderWindow &GetWindow();

    private:
        sf::RenderWindow m_window;
};
