/*
** EPITECH PROJECT, 2023
** core
** File description:
** Core
*/

#include "arcade/interfaces/IDisplay.hh"
#include <arcade/Core.hh>
#include <functional>
#include <string>
#include <vector>

// getters and setters for Core

std::vector<std::string> arc::Core::getSharedLibs() const
{
    return this->shared_libs;
}

std::vector<std::string> arc::Core::getSharedDisplays() const
{
    return this->shared_displays;
}

std::vector<std::string> arc::Core::getSharedGames() const
{
    return this->shared_games;
}

std::string arc::Core::getActiveDisplay() const
{
    return this->active_display;
}

std::string arc::Core::getActiveGame() const
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
