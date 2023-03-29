/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGame
*/

#pragma once

#include "arcade/Geometry.hh"
#include <Snake/Snake.hh>
#include <arcade/interfaces/IGame.hh>
#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IText.hh>
#include <arcade/interfaces/IWindow.hh>
#include <chrono>
#include <memory>
#include <string_view>
#include <vector>

namespace arc
{

    constexpr arc::Vector STARTING_POINT{10, 16};
    constexpr arc::Color HEAD_COLOR{50, 205, 50};
    constexpr arc::Color BODY_COLOR{0, 128, 0};
    constexpr arc::Color WALL_COLOR{255, 69, 0};
    constexpr arc::Color FRUIT_COLOR{255, 0, 0};
    constexpr arc::Vector FRUIT_STARTING_POS{3, 14};
    constexpr arc::Vector SCORE_POSITION{2, 0};
    constexpr arc::Vector HIGHSCORE_POSITION{12, 0};
    constexpr int MAP_SIZE = 20;
    constexpr int NEW_POINT = 100;
    constexpr arc::Color TEXT_COLOR{255, 255, 255};

    class SnakeGame : public IGame
    {
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
            void SetSprite(arc::IDisplay &display) final;
            void SetText(arc::IDisplay &display) final;

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
            std::vector<Tile> m_texts;
            std::vector<std::string> m_score;
            std::vector<int> m_score_number;
            Tile m_fruit;
    };

} // namespace arc
