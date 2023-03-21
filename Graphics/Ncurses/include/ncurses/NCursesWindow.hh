/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesWindow
*/

#pragma once

#include <string>
#include <ncurses.h>
#include <arcade/interfaces/IWindow.hh>

namespace arc {

    class NCursesWindow : public IWindow {
        public:
            NCursesWindow() = default;
            NCursesWindow(unsigned int x_coord, unsigned int y_coord, const std::string &name_window);
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
}