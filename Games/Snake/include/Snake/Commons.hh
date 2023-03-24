/*
** EPITECH PROJECT, 2023
** Include
** File description:
** Commons
*/

#pragma once

#include <arcade/interfaces/ISprite.hh>
#include <arcade/Geometry.hh>
#include <vector>

enum class Orient { N, E, S, W, NONE };

struct Tile {
        arc::Vector coord{0, 0};
        arc::Color color{0, 0, 0};
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
        void move_snake(int x_coord, int y_coord);

    private:
        Tile m_head_snake{};
        std::vector<Tile> m_snake_body{};
        Tile m_snake_tail{};
};
