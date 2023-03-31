/*
** EPITECH PROJECT, 2023
** core
** File description:
** gameLoop
*/

#include <arcade/Core.hh>
#include <arcade/core/CoreClock.hh>
#include <arcade/enum/EventEnum.hh>
#include <iostream>

void arc::Core::getEvents()
{
    arc::Event graphic_event = arc::Event::NONE;

    while ((graphic_event = this->display->GetEvent()) != arc::Event::NONE)
        this->handEvents(graphic_event);
}

void arc::Core::mainGameLoop()
{
    if (!this->display)
        throw Core::CoreException(NO_PARAM_ERR.data());
    this->changeGame("./lib/arcade_nibbler.so");
    this->game->SetSprite(this->getIDisplay().get());
    this->game->SetText(this->getIDisplay().get());
    while (this->mode != CoreMode::Quit) {
        if (this->clock.getElapsedTimeInS() > arc::CLOCK_UPDATE_TIME) {
            this->handDisplay();
            this->getEvents();
            this->game->PlayGame();
            this->clock.reset();
        }
    }
}
