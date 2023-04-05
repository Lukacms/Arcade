/*
** EPITECH PROJECT, 2023
** Nibbler
** File description:
** Nibbler
*/

#pragma once

#include "arcade/interfaces/IDisplay.hh"
#include "arcade/interfaces/ISprite.hh"
#include "arcade/interfaces/IWindow.hh"
#include <arcade/Geometry.hh>
#include <functional>
#include <memory>
#include <string>
#include <vector>

constexpr int const MAP_WIDTH = 20;
constexpr int const MAP_HEIGHT = 20;
constexpr int const POS_SNAKE_BASE_Y = 10;
constexpr int const POS_SNAKE_BASE_X = 16;
constexpr int const SCORE_WHEN_APPLE_EAT = 100;
constexpr arc::Color const BODY_COLOR{50, 205, 50};
constexpr arc::Color const HEAD_COLOR{50, 205, 50};
constexpr arc::Color const TAIL_COLOR{50, 205, 50};
constexpr arc::Color const FRUIT_COLOR{255, 0, 0};
constexpr arc::Vector STARTING_POINT{10, 16};
constexpr arc::Vector SCORE_POSITION{2, 0};
constexpr arc::Vector HIGHSCORE_POSITION{12, 0};
constexpr int MAP_SIZE = 20;
constexpr int NEW_POINT = 100;

enum class Orient { N, E, S, W, NONE };

struct Tile {
        arc::Vector coord{0, 0};
        Orient orientation{};
};

class Snake
{
    public:
        Snake();
        Snake(Snake const &to_copy) = delete;
        Snake(Snake &&to_move) = default;
        ~Snake() = default;
        Snake &operator=(Snake const &to_copy) = delete;
        Snake &operator=(Snake &&to_move) = default;

        void move_snake(int x_coord, int y_coord, Orient orientation);
        void changeOrientation(Orient orientation);
        void expand_snake(int x_coord, int y_coord, Orient orientation);
        void reset_snake();
        bool is_cell_snake(int x_coord, int y_coord);
        [[nodiscard]] Tile get_head_position() const;
        [[nodiscard]] std::vector<Tile> get_snake_tiles() const;

    private:
        Tile m_head_snake{};
        std::vector<Tile> m_snake_body{};
};
