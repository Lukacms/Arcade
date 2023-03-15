/*
** EPITECH PROJECT, 2023
** window
** File description:
** window
*/

#pragma once

namespace Arc
{
    class IWindow
    {
        public:
            virtual ~IWindow() = default;
            virtual const Arc::IWindow &GetWindow() = 0;
            virtual void OpenWindow() = 0;
            virtual void CloseWindow() = 0;
            virtual void CreateWindow() = 0;
            virtual void UpdateWindow() = 0;
    };
} // namespace Arc
