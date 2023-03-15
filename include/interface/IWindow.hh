/*
** EPITECH PROJECT, 2023
** window
** File description:
** window
*/

#pragma once

class IWindow
{
    public:
        virtual ~IWindow() = default;
        virtual const IWindow &GetWindow() = 0;
        virtual void OpenWindow() = 0;
        virtual void CloseWindow() = 0;
        virtual void CreateWindow() = 0;
        virtual void UpdateWindow() = 0;
};
