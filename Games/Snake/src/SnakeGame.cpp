/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGame
*/

#include "Snake/Commons.hh"
#include "arcade/interfaces/ISprite.hh"
#include <Snake/SnakeGame.hh>

/* Constructor && Destructor */

/* Methods */

void arc::SnakeGame::InitSnake()
{
    Tile snake_head;
    Tile snake_body;

    snake_head.coord = STARTING_POINT;
    snake_head.color = HEAD_COLOR;
    snake_body.coord = STARTING_POINT;
    snake_body.color = BODY_COLOR;
    this->m_snake.push_back(snake_head);
    for (int i = 0; i < 3; i++) {
        snake_body.coord.y -= i;
        this->m_snake.push_back(snake_body);
    }
}

void arc::SnakeGame::InitSnakeMap()
{
    Tile wall_tile;
    int x_coord = 0;
    int y_coord = 0;

    wall_tile.color = WALL_COLOR;
    for (; x_coord < MAP_SIZE; x_coord += 1) {
        wall_tile.coord = {x_coord, 0};
        this->m_map.push_back(wall_tile);
        wall_tile.coord = {x_coord, MAP_SIZE - 1};
        this->m_map.push_back(wall_tile);
    }
    for (y_coord = 1; y_coord < MAP_SIZE - 1; y_coord += 1) {
        wall_tile.coord = {0, y_coord};
        this->m_map.push_back(wall_tile);
        wall_tile.coord = {MAP_SIZE - 1, y_coord};
        this->m_map.push_back(wall_tile);
    }
}

void arc::SnakeGame::InitGame()
{
    this->InitSnake();
    this->InitSnakeMap();
}

void arc::SnakeGame::DisplayGame(IWindow &window)
{
    for (auto tile : this->m_snake) {
        this->m_sprite->setSpritePosition(tile.coord.x, tile.coord.y);
        this->m_sprite->setSpriteColor(tile.color.red, tile.color.green, tile.color.blue);
        this->m_sprite->drawSprite(window);
    }
    for (auto tile : this->m_map) {
        this->m_sprite->setSpritePosition(tile.coord.x, tile.coord.y);
        this->m_sprite->setSpriteColor(tile.color.red, tile.color.green, tile.color.blue);
        this->m_sprite->drawSprite(window);
    }
}