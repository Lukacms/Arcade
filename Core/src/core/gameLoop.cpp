/*
** EPITECH PROJECT, 2023
** core
** File description:
** gameLoop
*/

#include <arcade/Core.hh>
#include <arcade/core/CoreClock.hh>
#include <arcade/enum/EventEnum.hh>

void arc::Core::getEvents()
{
    arc::Event graphic_event = arc::Event::NONE;

    while ((graphic_event = this->display->GetEvent()) != arc::Event::NONE)
        this->handEvents(graphic_event);
}

void arc::Core::set_menu_desicion()
{
    if (this->menu.get_lib_game().empty() || this->menu.get_lib_graph().empty())
        return;
    arc::Core::changeDisplay(this->menu.get_lib_graph());
    arc::Core::changeGame(this->menu.get_lib_game());
    this->mode = CoreMode::Game;
}

void arc::Core::loadMenu()
{
    this->menu.set_lib_game(this->shared_games);
    this->menu.set_lib_graph(this->shared_displays);
    this->menu.SetText(*this->display);
    this->menu.SetSprite(*this->display);
}

void arc::Core::mainGameLoop()
{
    if (!this->display)
        throw Core::CoreException(NO_PARAM_ERR.data());
    this->loadMenu();
    while (this->mode != CoreMode::Quit) {
        if (this->clock.getElapsedTimeInS() > arc::CLOCK_UPDATE_TIME) {
            if (this->mode == CoreMode::Menu)
                set_menu_desicion();
            this->handDisplay();
            this->getEvents();
            this->clock.reset();
        }
    }
}
