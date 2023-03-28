/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGame
*/

#pragma once

#include <arcade/interfaces/IWindow.hh>
#include <arcade/interfaces/IGame.hh>
#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IText.hh>
#include <Snake/Snake.hh>
#include <memory>
#include <vector>
#include <chrono>

namespace arc {

    constexpr arc::Vector STARTING_POINT{10, 16};
    constexpr arc::Color HEAD_COLOR{50,205,50};
    constexpr arc::Color BODY_COLOR{0,128,0};
    constexpr arc::Color WALL_COLOR{255,69,0};
    constexpr arc::Color FRUIT_COLOR{255,0,0};
    constexpr arc::Vector FRUIT_STARTING_POS{3,14};
    constexpr int MAP_SIZE = 20;

    class SnakeGame : public IGame {
        public:
            SnakeGame() = default;
            SnakeGame(const SnakeGame &) = delete;
            SnakeGame(SnakeGame &&) = default;
            ~SnakeGame() override = default;
    
            SnakeGame &operator=(const SnakeGame &) = delete;
            SnakeGame &operator=(SnakeGame &&);

            void EventAnalisys(const arc::Event &event) final;
            void DisplayGame(IWindow &window) final;
            void ResetGame() final;
            void InitGame() final;
            void PlayGame() final;

        private:
            void InitSnakeMap();
            void MoveSnake();
            void CheckCollisions();
            void GenerateFruit();
            bool isFruitPositionOkay(int pos_x, int pos_y);

            Snake m_snake{};
            std::unique_ptr<ISprite> m_sprite;
            std::unique_ptr<IText> m_text;
            std::vector<Tile> m_map;
            Tile m_fruit;
            int m_score = 0;
    };

}
