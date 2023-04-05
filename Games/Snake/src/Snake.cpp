/*
** EPITECH PROJECT, 2023
** src
** File description:
** Snake
*/

#include "arcade/Geometry.hh"
#include <Snake/Snake.hh>
#include <Snake/SnakeGame.hh>

/* Constructor && Destructor */

Snake::Snake() noexcept
{
    Tile snake_body;

    this->m_snake_head.coord = arc::STARTING_POINT;
    this->m_snake_head.color = arc::HEAD_COLOR;
    this->m_snake_head.orientation = Orient::E;
    snake_body.color = arc::BODY_COLOR;
    snake_body.orientation = Orient::NONE;
    snake_body.coord = arc::STARTING_POINT;
    snake_body.coord.x -= 1;
    this->m_snake.push_back(snake_body);
    snake_body.coord.x -= 1;
    this->m_snake.push_back(snake_body);
    snake_body.coord.x -= 1;
    this->m_snake.push_back(snake_body);
}

/* Methods */

void Snake::moveSnake(int x_coord, int y_coord, Orient orientation)
{
    int size = this->m_snake.size() - 1;

    for (; size >= 1; size -= 1)
        this->m_snake[size].coord = this->m_snake[size - 1].coord;
    this->m_snake[0].coord = this->m_snake_head.coord;
    this->m_snake_head.coord.x += x_coord;
    this->m_snake_head.coord.y += y_coord * -1;
    this->m_snake_head.orientation = orientation;
}

void Snake::expandSnake(int x_coord, int y_coord, Orient orientation)
{
    Tile new_snake = {x_coord, y_coord, arc::BODY_COLOR, Orient::NONE};

    this->m_snake.push_back(new_snake);
}

void Snake::resetSnake()
{
    Tile snake_body;
    this->m_snake.clear();

    this->m_snake_head.coord = arc::STARTING_POINT;
    this->m_snake_head.color = arc::HEAD_COLOR;
    this->m_snake_head.orientation = Orient::E;
    snake_body.color = arc::BODY_COLOR;
    snake_body.orientation = Orient::NONE;
    snake_body.coord = arc::STARTING_POINT;
    for (int iterator = 1; iterator <= 4; iterator += 1) {
        snake_body.coord.x = arc::STARTING_POINT.x - iterator;
        this->m_snake.push_back(snake_body);
    }
}

arc::Vector Snake::getHeadPosition() const
{
    return this->m_snake_head.coord;
}

std::vector<Tile> Snake::getSnakeTiles() const
{
    std::vector<Tile> snake_tiles;

    snake_tiles.push_back(this->m_snake_head);
    for (auto iterator : this->m_snake)
        snake_tiles.push_back(iterator);
    return snake_tiles;
}

void Snake::changeOrientation(Orient orientation)
{
    this->m_snake_head.orientation = orientation;
}
