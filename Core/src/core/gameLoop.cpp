/*
** EPITECH PROJECT, 2023
** core
** File description:
** gameLoop
*/

#include <arcade/Core.hh>

void arc::Core::mainGameLoop()
{
    if (!this->display)
        throw Core::CoreException(NO_PARAM_ERR.data());
    this->changeGame("./lib/arcade_snake.so");
    this->game->SetSprite(this->getIDisplay().get());
    this->game->SetText(this->getIDisplay().get());
    while (this->mode != CoreMode::Quit) {
        this->handDisplay();
 //       this->handEvents();
    }
}
