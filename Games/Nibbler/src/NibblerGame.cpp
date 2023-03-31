/*
** EPITECH PROJECT, 2023
** src
** File description:
** NibblerGame
*/

#include "arcade/interfaces/IWindow.hh"
#include <Nibbler/Nibbler.hh>
#include <Nibbler/NibblerGame.hh>
#include <algorithm>
#include <iostream>
#include <string>

void NibblerGame::ResetGame()
{
    if (m_score.highscore < m_score.current_score)
        m_score.highscore = m_score.current_score;
    m_map_tile = m_level[0];
    m_fruits = m_fruits_level[0];
    m_snake.reset_snake();
}

void NibblerGame::EventAnalisys(const arc::Event &event)
{
    Tile snake_head = this->m_snake.get_snake_tiles()[0];

    if (event == arc::Event::LEFT && snake_head.orientation != Orient::E)
        this->m_snake.changeOrientation(Orient::W);
    if (event == arc::Event::RIGHT && snake_head.orientation != Orient::W)
        this->m_snake.changeOrientation(Orient::E);
    if (event == arc::Event::UP && snake_head.orientation != Orient::S)
        this->m_snake.changeOrientation(Orient::N);
    if (event == arc::Event::DOWN && snake_head.orientation != Orient::N)
        this->m_snake.changeOrientation(Orient::S);
}

void NibblerGame::SetSprite(arc::IDisplay &display)
{
    if (this->m_sprite)
        this->m_sprite.release();
    this->m_sprite = display.createSprite();
}

void NibblerGame::SetText(arc::IDisplay &display)
{
    if (this->m_text)
        this->m_text.release();
    this->m_text = display.createText();
}

void NibblerGame::check_if_corner_s()
{
    Tile snake_head = m_snake.get_snake_tiles()[0];
    std::vector<Tile> snake = m_snake.get_snake_tiles();

    auto left = [&](Tile tile) -> bool {
        return snake_head.coord.x - 1 == tile.coord.x && snake_head.coord.y == tile.coord.y;
    };
    auto right = [&](Tile tile) -> bool {
        return snake_head.coord.x + 1 == tile.coord.x && snake_head.coord.y == tile.coord.y;
    };
    if (std::any_of(m_map_tile.begin(), m_map_tile.end(), left) &&
        std::any_of(m_map_tile.begin(), m_map_tile.end(), right))
        return;
    if (!std::any_of(m_map_tile.begin(), m_map_tile.end(), left) &&
        !std::any_of(m_map_tile.begin(), m_map_tile.end(), right))
        return;
    if (!std::any_of(m_map_tile.begin(), m_map_tile.end(), left) &&
        std::any_of(m_map_tile.begin(), m_map_tile.end(), right)) {
        m_snake.changeOrientation(Orient::W);
        return;
    }
    if (std::any_of(m_map_tile.begin(), m_map_tile.end(), left) &&
        !std::any_of(m_map_tile.begin(), m_map_tile.end(), right)) {
        m_snake.changeOrientation(Orient::E);
        return;
    }
}

void NibblerGame::check_if_corner_n()
{
    Tile snake_head = m_snake.get_snake_tiles()[0];
    std::vector<Tile> snake = m_snake.get_snake_tiles();

    auto left = [&](Tile tile) -> bool {
        return snake_head.coord.x - 1 == tile.coord.x && snake_head.coord.y == tile.coord.y;
    };
    auto right = [&](Tile tile) -> bool {
        return snake_head.coord.x + 1 == tile.coord.x && snake_head.coord.y == tile.coord.y;
    };
    if (std::any_of(m_map_tile.begin(), m_map_tile.end(), left) &&
        std::any_of(m_map_tile.begin(), m_map_tile.end(), right))
        return;
    if (!std::any_of(m_map_tile.begin(), m_map_tile.end(), left) &&
        !std::any_of(m_map_tile.begin(), m_map_tile.end(), right))
        return;
    if (!std::any_of(m_map_tile.begin(), m_map_tile.end(), left) &&
        std::any_of(m_map_tile.begin(), m_map_tile.end(), right)) {
        m_snake.changeOrientation(Orient::W);
        return;
    }
    if (std::any_of(m_map_tile.begin(), m_map_tile.end(), left) &&
        !std::any_of(m_map_tile.begin(), m_map_tile.end(), right)) {
        m_snake.changeOrientation(Orient::E);
        return;
    }
}

void NibblerGame::check_if_corner_e()
{
    Tile snake_head = m_snake.get_snake_tiles()[0];
    std::vector<Tile> snake = m_snake.get_snake_tiles();

    auto down = [&](Tile tile) -> bool {
        return snake_head.coord.x == tile.coord.x && snake_head.coord.y + 1 == tile.coord.y;
    };
    auto up = [&](Tile tile) -> bool {
        return snake_head.coord.x == tile.coord.x && snake_head.coord.y - 1 == tile.coord.y;
    };
    if (std::any_of(m_map_tile.begin(), m_map_tile.end(), up) &&
        std::any_of(m_map_tile.begin(), m_map_tile.end(), down))
        return;
    if (!std::any_of(m_map_tile.begin(), m_map_tile.end(), up) &&
        !std::any_of(m_map_tile.begin(), m_map_tile.end(), down))
        return;
    if (!std::any_of(m_map_tile.begin(), m_map_tile.end(), up) &&
        std::any_of(m_map_tile.begin(), m_map_tile.end(), down)) {
        m_snake.changeOrientation(Orient::N);
        return;
    }
    if (std::any_of(m_map_tile.begin(), m_map_tile.end(), up) &&
        !std::any_of(m_map_tile.begin(), m_map_tile.end(), down)) {
        m_snake.changeOrientation(Orient::S);
        return;
    }
}

void NibblerGame::check_if_corner_w()
{
    Tile snake_head = m_snake.get_snake_tiles()[0];
    std::vector<Tile> snake = m_snake.get_snake_tiles();

    auto down = [&](Tile tile) -> bool {
        return snake_head.coord.x == tile.coord.x && snake_head.coord.y + 1 == tile.coord.y;
    };
    auto up = [&](Tile tile) -> bool {
        return snake_head.coord.x == tile.coord.x && snake_head.coord.y - 1 == tile.coord.y;
    };
    if (std::any_of(m_map_tile.begin(), m_map_tile.end(), up) &&
        std::any_of(m_map_tile.begin(), m_map_tile.end(), down))
        return;
    if (!std::any_of(m_map_tile.begin(), m_map_tile.end(), up) &&
        !std::any_of(m_map_tile.begin(), m_map_tile.end(), down))
        return;
    if (!std::any_of(m_map_tile.begin(), m_map_tile.end(), up) &&
        std::any_of(m_map_tile.begin(), m_map_tile.end(), down)) {
        m_snake.changeOrientation(Orient::N);
        return;
    }
    if (std::any_of(m_map_tile.begin(), m_map_tile.end(), up) &&
        !std::any_of(m_map_tile.begin(), m_map_tile.end(), down)) {
        m_snake.changeOrientation(Orient::S);
        return;
    }
}

void NibblerGame::move_snake()
{
    Tile snake_head = m_snake.get_head_position();
    std::vector<Tile> snake = m_snake.get_snake_tiles();

    for (auto iterator : m_map_tile) {
        if (iterator.coord.x == snake_head.coord.x + 1 && iterator.coord.y == snake_head.coord.y &&
            snake_head.orientation == Orient::E) {
            check_if_corner_e();
            return;
        }
        if (iterator.coord.x == snake_head.coord.x - 1 && iterator.coord.y == snake_head.coord.y &&
            snake_head.orientation == Orient::W) {
            check_if_corner_w();
            return;
        }
        if (iterator.coord.x == snake_head.coord.x && iterator.coord.y == snake_head.coord.y - 1 &&
            snake_head.orientation == Orient::N) {
            check_if_corner_n();
            return;
        }
        if (iterator.coord.x == snake_head.coord.x && iterator.coord.y == snake_head.coord.y + 1 &&
            snake_head.orientation == Orient::S) {
            check_if_corner_s();
            return;
        }
    }
    if (snake_head.orientation == Orient::N)
        m_snake.move_snake(0, 1, Orient::N);
    if (snake_head.orientation == Orient::S)
        m_snake.move_snake(0, -1, Orient::S);
    if (snake_head.orientation == Orient::E)
        m_snake.move_snake(1, 0, Orient::E);
    if (snake_head.orientation == Orient::W)
        m_snake.move_snake(-1, 0, Orient::W);
}

void NibblerGame::check_colision()
{
    std::vector<Tile> snake = m_snake.get_snake_tiles();
    int size = snake.size();

    for (auto &fruit : m_fruits) {
        if (snake[0].coord.x == fruit.coord.x && snake[0].coord.y == fruit.coord.y) {
            this->m_snake.expand_snake(0, 0, Orient::NONE);
            fruit.coord.x = -1;
            fruit.coord.y = -1;
            return;
        }
    }
    for (int iterator = 1; iterator < size; iterator += 1) {
        if (snake[0].coord.x == snake[iterator].coord.x &&
            snake[0].coord.y == snake[iterator].coord.y) {
            this->ResetGame();
            return;
        }
    }
}

void NibblerGame::PlayGame()
{
    check_colision();
    move_snake();
}

void NibblerGame::DisplayGame(arc::IWindow &window)
{
    std::vector<Tile> snake = this->m_snake.get_snake_tiles();
    std::string text;

    window.UpdateWindow();
    for (auto tile : snake) {
        std::cout << "snake tile: (" << tile.coord.x << ", " << tile.coord.y << ")\n";
        m_sprite->setSpritePosition(tile.coord.x, tile.coord.y);
        m_sprite->setSpriteColor(BODY_COLOR.red, BODY_COLOR.green, BODY_COLOR.blue);
        m_sprite->drawSprite(window);
    }
    std::cout << '\n';
    std::cout << '\n';
    std::cout << '\n';
    for (auto tile : m_map_tile) {
        //        std::cout << "map tile: (" << tile.coord.x << ", " << tile.coord.y << ")\n";
        m_sprite->setSpritePosition(tile.coord.x, tile.coord.y);
        m_sprite->setSpriteColor(WALL_COLOR.red, WALL_COLOR.green, WALL_COLOR.blue);
        m_sprite->drawSprite(window);
    }
    for (auto tile : m_fruits) {
        m_sprite->setSpritePosition(tile.coord.x, tile.coord.y);
        m_sprite->setSpriteColor(FRUIT_COLOR.red, FRUIT_COLOR.green, FRUIT_COLOR.blue);
        m_sprite->drawSprite(window);
    }
    /* this->m_text->setFont("./assets/font/arcade.ttf");
     for (int iterator = 0; iterator < 2; iterator += 1) {
         this->m_text->setTextPosition(this->m_texts[iterator].coord.x,
                                       this->m_texts[iterator].coord.y);
         this->m_text->setTextColor(TEXT_COLOR.red, TEXT_COLOR.green, TEXT_COLOR.blue);
         text = std::to_string(m_score.current_score);
         text.insert(0, 9 - text.size(), '0');
         this->m_text->setText(std::to_string(m_score.current_score) + text);
         this->m_text->drawText(window);
     }
     */
    window.OpenWindow();
}
