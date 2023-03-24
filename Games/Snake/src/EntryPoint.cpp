/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include <arcade/interfaces/IGame.hh>
#include <Snake/SnakeGame.hh>
#include <memory>

extern "C" {

    std::unique_ptr<arc::IGame> entry_point() { // NOLINT
        std::unique_ptr<arc::IGame> snake_game = std::make_unique<arc::SnakeGame>();

        snake_game->InitGame();
        return snake_game;
    }
}