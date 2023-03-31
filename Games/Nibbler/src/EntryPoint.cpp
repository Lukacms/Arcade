/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** EntryPoint
*/

#include <Nibbler/NibblerGame.hh>
#include <arcade/interfaces/IGame.hh>
#include <memory>

extern "C" {

std::unique_ptr<arc::IGame> entryPoint()
{ // NOLINT
    std::unique_ptr<arc::IGame> nibbler_game = std::make_unique<NibblerGame>();

    nibbler_game->InitGame();
    return nibbler_game;
}
}