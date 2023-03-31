/*
** EPITECH PROJECT, 2023
** src
** File description:
** Nibbler
*/

#include "arcade/interfaces/ISprite.hh"
#include <Nibbler/Nibbler.hh>
#include <algorithm>
#include <bits/ranges_algo.h>
#include <functional>
#include <iostream>
#include <memory>

Snake::Snake()
{
    Tile snake_body;

    m_head_snake.coord = STARTING_POINT;
    m_head_snake.orientation = Orient::W;
    snake_body.orientation = Orient::NONE;
    snake_body.coord = STARTING_POINT;
    snake_body.coord.x -= 1;
    m_snake_body.push_back(snake_body);
    snake_body.coord.x -= 1;
    m_snake_body.push_back(snake_body);
    snake_body.coord.x -= 1;
    m_snake_body.push_back(snake_body);
}

void Snake::move_snake(int x_coord, int y_coord, Orient orientation)
{
    int size = m_snake_body.size();

    for (; size >= 1; size -= 1)
        m_snake_body[size].coord = m_snake_body[size - 1].coord;
    m_snake_body[0].coord = m_head_snake.coord;
    m_head_snake.coord.x += x_coord;
    m_head_snake.coord.y += y_coord * -1;
    m_head_snake.orientation = orientation;
}

void Snake::expand_snake(int x_coord, int y_coord, Orient orientation)
{
    m_snake_body.emplace_back(Tile{x_coord, y_coord, Orient::NONE});
}

void Snake::reset_snake()
{
    Tile snake_body;
    m_snake_body.clear();
    this->m_head_snake.coord = STARTING_POINT;
    this->m_head_snake.orientation = Orient::E;
    snake_body.orientation = Orient::NONE;
    snake_body.coord = STARTING_POINT;
    for (int iterator = 1; iterator <= 4; iterator += 1) {
        snake_body.coord.x = STARTING_POINT.x - iterator;
        m_snake_body.push_back(snake_body);
    }
}

Tile Snake::get_head_position() const
{
    return m_head_snake;
}

bool Snake::is_cell_snake(int x_coord, int y_coord)
{
    auto comp = [&](Tile &tile) -> bool {
        return tile.coord.x == x_coord && tile.coord.y == y_coord;
    };
    return std::ranges::any_of(m_snake_body.begin(), m_snake_body.end(), comp);
}

void Snake::changeOrientation(Orient orientation)
{
    m_head_snake.orientation = orientation;
}

std::vector<Tile> Snake::get_snake_tiles() const
{
    std::vector<Tile> snake_tiles;

    snake_tiles.push_back(m_head_snake);
    for (auto iterator : m_snake_body)
        snake_tiles.push_back(iterator);
    return snake_tiles;
}
