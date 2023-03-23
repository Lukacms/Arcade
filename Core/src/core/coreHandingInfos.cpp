/*
** EPITECH PROJECT, 2023
** core
** File description:
** coreHandingInfos
*/

#include <arcade/Core.hh>
#include <arcade/enum/EventEnum.hh>
#include <functional>
#include <map>

static const std::map<const arc::Event, std::function<void(arc::Core &)>> EVENT_MAP = {
    {arc::Event::CHANGE_GAME_L, [](arc::Core &core) -> void {
     }}};

// this method should just give the display method, window to the game
void arc::Core::handDisplay()
{
    this->game->DisplayGame(this->display->GetWindow());
}

// this method should analyse if an event should change library, quit or be analysed by the game
void arc::Core::handEvents()
{
    arc::Event graphic_event = this->display->GetEvent();

    for (auto event : EVENT_MAP) {
        if (event.first == graphic_event) {
            event.second(*this);
            return;
        }
    }
    this->game->EventAnalisys(graphic_event);
}
