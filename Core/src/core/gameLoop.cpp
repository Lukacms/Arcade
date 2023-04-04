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
    this->changeGame("./lib/arcade_snake.so");
    this->game->SetSprite(this->getIDisplay().get());
    this->game->SetText(this->getIDisplay().get());
    this->menu.set_lib_game(this->shared_games);
    this->menu.set_lib_graph(this->shared_displays);
    this->menu.SetText(*this->display);
    this->menu.SetSprite(*this->display);
    while (this->mode != CoreMode::Quit) {
        if (this->clock.getElapsedTimeInS() > arc::CLOCK_UPDATE_TIME) {
            this->handDisplay();
            this->getEvents();
            this->clock.reset();
        }
    }
}
