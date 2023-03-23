/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGame
*/

#pragma once

#include "arcade/interfaces/IWindow.hh"
#include <Snake/Commons.hh>
#include <arcade/interfaces/IGame.hh>
#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IText.hh>
#include <memory>
#include <vector>

namespace arc {

    constexpr arc::Vector STARTING_POINT{10, 10};
    constexpr arc::Color HEAD_COLOR{50,205,50};
    constexpr arc::Color BODY_COLOR{0,128,0};
    constexpr arc::Color WALL_COLOR{255,69,0};
    constexpr int MAP_SIZE = 20;

    class SnakeGame : public IGame {
        public:
            SnakeGame() = default;
            SnakeGame(const SnakeGame &) = delete;
            SnakeGame(SnakeGame &&) = default;
            ~SnakeGame() override = default;
    
            SnakeGame &operator=(const SnakeGame &) = delete;
            SnakeGame &operator=(SnakeGame &&);

            void DisplayGame(IWindow &window) override;
            void InitGame() override;

        private:

            void InitSnakeMap();
            void InitSnake();

            std::unique_ptr<ISprite> m_sprite;
            std::unique_ptr<IText> m_text;
            std::vector<Tile> m_snake;
            std::vector<Tile> m_map;
            int m_score = 0;
    };

}
