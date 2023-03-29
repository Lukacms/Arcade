/*
** EPITECH PROJECT, 2023
** Nibbler
** File description:
** Nibbler
*/

#pragma once

#include <arcade/Geometry.hh>
#include <vector>

constexpr int const MAP_WIDTH = 20;
constexpr int const MAP_HEIGHT = 20;
constexpr int POS_SNAKE_BASE_X = 19;

enum class Orient { N, E, S, W, NONE };

struct Tile {
        arc::Vector coord{0, 0};
        Orient orientation{};
};

class Snake
{
    public:
        Snake() = default;
        Snake(Snake const &to_copy) = default;
        Snake(Snake &&to_move) = default;
        ~Snake() = default;
        Snake &operator=(Snake const &to_copy) = default;
        Snake &operator=(Snake &&to_move) = default;
        void move_snake(int x_coord, int y_coord, Orient orientation);
        void expand_snake();
        void reset_snake();
        bool is_cell_snake(int x_coord, int y_coord);
        [[nodiscard]] arc::Vector get_head_position() const;

    private:
        Tile m_head_snake{};
        std::vector<Tile> m_snake_body{};
        Tile m_snake_tail{};
};
