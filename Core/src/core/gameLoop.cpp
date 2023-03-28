/*
** EPITECH PROJECT, 2023
** core
** File description:
** gameLoop
*/

#include <arcade/Core.hh>

void arc::Core::displayGameOrMenu()
{
    if (this->mode == CoreMode::Game)
        this->game->DisplayGame(this->display->GetWindow());
    else
        this->menu.display(this->display->GetWindow());
}

void arc::Core::mainGameLoop()
{
    if (!this->display)
        throw Core::CoreException(NO_PARAM_ERR.data());
    while (this->mode != CoreMode::Quit) {
        this->displayGameOrMenu();
        this->handEvents();
    }
}
