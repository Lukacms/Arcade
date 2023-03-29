/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGame
*/

#include <arcade/enum/EventEnum.hh>
#include <Snake/Snake.hh>
#include <arcade/interfaces/ISprite.hh>
#include <Snake/SnakeGame.hh>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <vector>

/* Constructor && Destructor */

/* Methods */

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
    Snake new_snake{};

    std::srand(std::time(nullptr));
    this->InitSnakeMap();
    this->m_snake = new_snake;
    this->m_fruit.color = arc::FRUIT_COLOR;
    this->m_fruit.coord = FRUIT_STARTING_POS;
    this->m_fruit.orientation = Orient::NONE;
}

void arc::SnakeGame::DisplayGame(IWindow &window)
{
    std::vector<Tile> snake = this->m_snake.getSnakeTiles();

    window.UpdateWindow();
    for (auto tile : snake) {
        this->m_sprite->setSpritePosition(tile.coord.x, tile.coord.y);
        this->m_sprite->setSpriteColor(tile.color.red, tile.color.green, tile.color.blue);
        this->m_sprite->drawSprite(window);
    }
    for (auto tile : this->m_map) {
        this->m_sprite->setSpritePosition(tile.coord.x, tile.coord.y);
        this->m_sprite->setSpriteColor(tile.color.red, tile.color.green, tile.color.blue);
        this->m_sprite->drawSprite(window);
    }
    this->m_sprite->setSpritePosition(this->m_fruit.coord.x, this->m_fruit.coord.y);
    this->m_sprite->setSpriteColor(this->m_fruit.color.red, this->m_fruit.color.green, this->m_fruit.color.blue);
    this->m_sprite->drawSprite(window);
    window.OpenWindow();
}

void arc::SnakeGame::EventAnalisys(const arc::Event &event)
{
    Tile snake_head = this->m_snake.getSnakeTiles()[0];

    if (event == Event::LEFT && snake_head.orientation != Orient::E)
        this->m_snake.changeOrientation(Orient::W);
    if (event == Event::RIGHT && snake_head.orientation != Orient::W)
        this->m_snake.changeOrientation(Orient::E);
    if (event == Event::UP && snake_head.orientation != Orient::S)
        this->m_snake.changeOrientation(Orient::N);
    if (event == Event::DOWN && snake_head.orientation != Orient::N)
        this->m_snake.changeOrientation(Orient::S);
}

void arc::SnakeGame::ResetGame()
{
    this->m_snake.resetSnake();
    m_score = 0;
}

void arc::SnakeGame::PlayGame()
{
    this->MoveSnake();
    this->CheckCollisions();
}

void arc::SnakeGame::MoveSnake()
{
    Tile snake_head = this->m_snake.getSnakeTiles()[0];

    if (snake_head.orientation == Orient::N)
        this->m_snake.moveSnake(0, 1, Orient::N);
    if (snake_head.orientation == Orient::S)
        this->m_snake.moveSnake(0, -1, Orient::S);
    if (snake_head.orientation == Orient::E)
        this->m_snake.moveSnake(1, 0, Orient::E);
    if (snake_head.orientation == Orient::W)
        this->m_snake.moveSnake(-1, 0, Orient::W);
}

void arc::SnakeGame::CheckCollisions()
{
    std::vector<Tile> snake = this->m_snake.getSnakeTiles();
    int size = snake.size();

    for (auto iterator : m_map) {
        if (iterator.coord.x == snake[0].coord.x && iterator.coord.y == snake[0].coord.y) {
            this->ResetGame();
            return;
        }
    }
    if (snake[0].coord.x == m_fruit.coord.x && snake[0].coord.y == m_fruit.coord.y) {
        this->GenerateFruit();
        this->m_snake.expandSnake(0, 0, Orient::NONE);
        return;
    }
    for (int iterator = 1; iterator < size; iterator += 1) {
        if (snake[0].coord.x == snake[iterator].coord.x && snake[0].coord.y == snake[iterator].coord.y) {
            this->ResetGame();
            return;
        }
    }
}

void arc::SnakeGame::GenerateFruit()
{
    int pos_x;
    int pos_y;
    bool is_correct = false;

    while (!is_correct) {
        pos_x = std::rand() % MAP_SIZE;
        pos_y = std::rand() % MAP_SIZE;
        if (this->isFruitPositionOkay(pos_x, pos_y))
            is_correct = true;
    }
    this->m_fruit.coord = {pos_x, pos_y};
}

bool arc::SnakeGame::isFruitPositionOkay(int pos_x, int pos_y)
{
    for (auto iterator : m_map) {
        if (iterator.coord.x == pos_x && iterator.coord.y == pos_y)
            return false;
    }
    for (auto iterator : this->m_snake.getSnakeTiles()) {
        if (iterator.coord.x == pos_x && iterator.coord.y == pos_y)
            return false;
    }
    return true;
}

void arc::SnakeGame::SetSprite(arc::IDisplay &display)
{
    this->m_sprite = display.createSprite();
}

void arc::SnakeGame::SetText(arc::IDisplay &display)
{
    this->m_text = display.createText();
}
