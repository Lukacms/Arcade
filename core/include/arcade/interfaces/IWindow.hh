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
            IWindow() = delete;
            IWindow(IWindow const &to_copy) = delete;
            IWindow(IWindow &&to_move) = delete;
            IWindow &operator=(IWindow const &to_copy) = delete;
            IWindow &operator=(IWindow const &&to_move) = delete;
            virtual ~IWindow() = default;
            [[nodiscard]] virtual const arc::IWindow &GetWindow() = 0;
            virtual void OpenWindow() = 0;
            virtual void CloseWindow() = 0;
            virtual void CreateWindow() = 0;
            virtual void UpdateWindow() = 0;
    };
} // namespace arc
