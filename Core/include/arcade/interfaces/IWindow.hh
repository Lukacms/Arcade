/*
** EPITECH PROJECT, 2023
** window
** File description:
** window
*/

#pragma once

namespace arc
{
    class IWindow
    {
        public:
            virtual ~IWindow() = default;
            virtual void OpenWindow() = 0;
            virtual void CloseWindow() = 0;
            virtual void CreateWindow(unsigned int x_coord, unsigned int y_coord) = 0;
            virtual void UpdateWindow() = 0;
    };
} // namespace arc
