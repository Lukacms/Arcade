/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SnakeGame */

#include <Snake/Snake.hh>
#include <Snake/SnakeGame.hh>
#include <arcade/enum/EventEnum.hh>
#include <arcade/interfaces/ISprite.hh>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
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

void arc::SnakeGame::setGameOverTile()
{
    this->m_game_over.color = TEXT_COLOR;
    this->m_game_over.coord = GAME_OVER_POSITION;
    this->m_game_over.orientation = Orient::NONE;
}

void arc::SnakeGame::InitGame()
{
    Snake new_snake{};
    Tile text_tile;

    std::srand(std::time(nullptr));
    this->InitSnakeMap();
    this->m_snake = new_snake;
    this->m_fruit.color = arc::FRUIT_COLOR;
    this->m_fruit.coord = FRUIT_STARTING_POS;
    this->m_fruit.orientation = Orient::NONE;
    text_tile.orientation = Orient::NONE;
    text_tile.color = TEXT_COLOR;
    text_tile.coord = SCORE_POSITION;
    this->m_texts.push_back(text_tile);
    text_tile.coord = HIGHSCORE_POSITION;
    this->m_texts.push_back(text_tile);
    this->m_score_number.emplace_back(0);
    this->m_score_number.emplace_back(0);
    this->m_score.emplace_back("SCORE : ");
    this->m_score.emplace_back("HI-SCORE : ");
    this->getHighScore();
    this->setGameOverTile();
}

void arc::SnakeGame::DisplayGame(IWindow &window)
{
    std::vector<Tile> snake = this->m_snake.getSnakeTiles();
    std::string text;

    window.UpdateWindow();
    if (this->m_state != GameState::GameOver) {
        for (auto tile : snake) {
            this->m_sprite->setSpritePosition(tile.coord.x, tile.coord.y);
            this->m_sprite->setSpriteColor(tile.color.red, tile.color.green, tile.color.blue);
            this->m_sprite->drawSprite(window);
        }
    }
    for (auto tile : this->m_map) {
        this->m_sprite->setSpritePosition(tile.coord.x, tile.coord.y);
        this->m_sprite->setSpriteColor(tile.color.red, tile.color.green, tile.color.blue);
        this->m_sprite->drawSprite(window);
    }
    this->m_sprite->setSpritePosition(this->m_fruit.coord.x, this->m_fruit.coord.y);
    this->m_sprite->setSpriteColor(this->m_fruit.color.red, this->m_fruit.color.green,
                                   this->m_fruit.color.blue);
    this->m_sprite->drawSprite(window);
    this->m_text->setFont("./assets/font/arcade.ttf");
    for (int iterator = 0; iterator < 2; iterator += 1) {
        this->m_text->setTextPosition(this->m_texts[iterator].coord.x,
                                      this->m_texts[iterator].coord.y);
        this->m_text->setTextColor(this->m_texts[iterator].color.red,
                                   this->m_texts[iterator].color.green,
                                   this->m_texts[iterator].color.blue);
        text = std::to_string(this->m_score_number[iterator]);
        text.insert(0, 9 - text.size(), '0');
        this->m_text->setText(this->m_score[iterator] + text);
        this->m_text->drawText(window);
    }
    if (this->m_state == GameState::GameOver) {
        this->m_text->setText("Press R to restart");
        this->m_text->setTextColor(this->m_game_over.color.red, this->m_game_over.color.green, this->m_game_over.color.blue);
        this->m_text->setTextPosition(this->m_game_over.coord.x, this->m_game_over.coord.y);
        this->m_text->drawText(window);
    }
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
    if (event == Event::RESTART)
        this->ResetGame();
}

void arc::SnakeGame::ResetGame()
{
    this->m_snake.resetSnake();
    this->m_score_number[0] = 0;
    this->GenerateFruit(false);
    this->saveHighScore();
    this->m_state = GameState::Play;
}

void arc::SnakeGame::PlayGame()
{
    if (this->m_state == GameState::Play) {
        this->MoveSnake();
        this->CheckCollisions();
    }
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
            this->m_state = GameState::GameOver;
            return;
        }
    }
    if (snake[0].coord.x == m_fruit.coord.x && snake[0].coord.y == m_fruit.coord.y) {
        this->GenerateFruit(true);
        this->m_snake.expandSnake(0, 0, Orient::NONE);
        return;
    }
    for (int iterator = 1; iterator < size; iterator += 1) {
        if (snake[0].coord.x == snake[iterator].coord.x &&
            snake[0].coord.y == snake[iterator].coord.y) {
            this->m_state = GameState::GameOver;
            return;
        }
    }
}

void arc::SnakeGame::GenerateFruit(bool is_point)
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
    if (is_point)
        this->m_score_number[0] += NEW_POINT;
    if (this->m_score_number[0] > this->m_score_number[1])
        this->m_score_number[1] = this->m_score_number[0];
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
    if (this->m_sprite)
        this->m_sprite.release();
    this->m_sprite = display.createSprite();
}

void arc::SnakeGame::SetText(arc::IDisplay &display)
{
    if (this->m_text)
        this->m_text.release();
    this->m_text = display.createText();
}

void arc::SnakeGame::getHighScore()
{
    std::ifstream hiscore_stream{"./save/hiscore.txt"};
    std::string hiscore;

    if (!hiscore_stream.is_open()) {
        this->m_score_number[1] = 0;
        return;
    }
    hiscore_stream >> hiscore;
    for (auto character : hiscore) {
        if (character < '0' || character > '9') {
            this->m_score_number[1] = 0;
            return;
        }
    }
    this->m_score_number[1] = std::stoi(hiscore);
    hiscore_stream.close();
}

void arc::SnakeGame::saveHighScore()
{
    std::ofstream hiscore_stream{"./save/hiscore.txt"};

    hiscore_stream << std::to_string(this->m_score_number[1]) << std::endl;
    hiscore_stream.close();
}