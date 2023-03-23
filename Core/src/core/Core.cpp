/*
** EPITECH PROJECT, 2023
** core
** File description:
** Core
*/

#include <arcade/Core.hh>
#include <arcade/interfaces/IDisplay.hh>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// getters and setters for Core

const std::vector<std::string> &arc::Core::getSharedDisplays() const
{
    return this->shared_displays;
}

const std::vector<std::string> &arc::Core::getSharedGames() const
{
    return this->shared_games;
}

const std::string &arc::Core::getActiveDisplay() const
{
    return this->active_display;
}

const std::string &arc::Core::getActiveGame() const
{
    return this->active_game;
}

std::reference_wrapper<arc::IDisplay> arc::Core::getIDisplay() const
{
    return std::ref(*this->display);
}

std::reference_wrapper<arc::IGame> arc::Core::getIGame() const
{
    return std::ref(*this->game);
}

// methods for CoreException

const char *arc::Core::CoreException::what() const noexcept
{
    return this->error_msg.c_str();
}
