/*
** EPITECH PROJECT, 2023
** core
** File description:
** gameLoop
*/

#include <arcade/Core.hh>
#include <arcade/enum/EventEnum.hh>
#include <iostream>

void arc::Core::mainGameLoop()
{
    arc::Event graphic_event;

    if (!this->display)
        throw Core::CoreException(NO_PARAM_ERR.data());
    this->changeGame("./lib/arcade_snake.so");
    this->game->SetSprite(this->getIDisplay().get());
    this->game->SetText(this->getIDisplay().get());
    while (this->mode != CoreMode::Quit) {
        this->handDisplay();
        while ((graphic_event = this->display->GetEvent()) != arc::Event::NONE)
            this->handEvents(graphic_event);
        this->game->PlayGame();
    }
}
