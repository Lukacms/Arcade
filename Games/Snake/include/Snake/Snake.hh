/*
** EPITECH PROJECT, 2023
** Snake
** File description:
** Snake
*/

#pragma once

#include <arcade/Geometry.hh>
#include <arcade/interfaces/ISprite.hh>
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
        Snake() noexcept;
        Snake(Snake const &to_copy) = default;
        Snake(Snake &&to_move) = default;
        ~Snake() = default;

        Snake &operator=(Snake const &to_copy) = default;
        Snake &operator=(Snake &&to_move) = default;

        void moveSnake(int x_coord, int y_coord, Orient orientation);
        void expandSnake(int x_coord, int y_coord, Orient orientation);
        void resetSnake();
        void changeOrientation(Orient orientation);
        [[nodiscard]] arc::Vector getHeadPosition() const;
        [[nodiscard]] std::vector<Tile> getSnakeTiles() const;

    private:
        Tile m_snake_head{};
        std::vector<Tile> m_snake{};
};
