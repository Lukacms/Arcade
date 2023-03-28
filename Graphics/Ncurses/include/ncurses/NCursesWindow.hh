/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesWindow
*/

#pragma once

#include <arcade/interfaces/IWindow.hh>
#include <ncurses.h>
#include <string>

namespace arc
{
    constexpr const int BACKSPACE = 127;

    class NCursesWindow : public IWindow
    {
        public:
            NCursesWindow() = default;
            NCursesWindow(unsigned int x_coord, unsigned int y_coord);
            NCursesWindow(NCursesWindow const &to_copy) = delete;
            NCursesWindow &operator=(NCursesWindow const &to_copy) = delete;
            NCursesWindow &operator=(NCursesWindow const &&to_move) = delete;
            NCursesWindow(NCursesWindow &&to_move) = delete;
            ~NCursesWindow() override;

            void OpenWindow() final;
            void CloseWindow() final;
            void CreateWindow(unsigned int x_coord, unsigned int y_coord) final;
            void UpdateWindow() final;
            [[nodiscard]] WINDOW *GetWindow();

        private:
            WINDOW *m_window = nullptr;
    };
} // namespace arc