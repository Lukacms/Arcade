/*
** EPITECH PROJECT, 2023
** core
** File description:
** gameLoop
*/

#include <arcade/Core.hh>
#include <arcade/enum/EventEnum.hh>

void arc::Core::mainGameLoop()
{
    arc::Event graphic_event = this->display->GetEvent();

    if (!this->display)
        throw Core::CoreException(NO_PARAM_ERR.data());
    while (this->mode != CoreMode::Quit) {
        this->handDisplay();
        while ((graphic_event = this->display->GetEvent()) != arc::Event::NONE)
            this->handEvents(graphic_event);
    }
}
