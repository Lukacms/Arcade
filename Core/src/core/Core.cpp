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

const std::string &arc::Core::getNextDisplay()
{
    if (this->display_ind >= this->shared_displays.size() - 1)
        this->display_ind = 0;
    else
        this->display_ind++;
    return this->shared_displays[this->display_ind];
}

const std::string &arc::Core::getPrevDisplay()
{
    if (this->display_ind == 0)
        this->display_ind = this->shared_displays.size() - 1;
    else
        this->display_ind--;
    return this->shared_displays[this->display_ind];
}

const std::string &arc::Core::getNextGame()
{
    if (this->game_ind >= this->shared_games.size() - 1)
        this->game_ind = 0;
    else
        this->game_ind++;
    return this->shared_games[this->game_ind];
}

const std::string &arc::Core::getPrevGame()
{
    if (this->game_ind == 0)
        this->game_ind = this->shared_games.size() - 1;
    else
        this->game_ind--;
    return this->shared_games[this->game_ind];
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
