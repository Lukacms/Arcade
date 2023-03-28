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
    {arc::Event::CHANGE_GAME_L,
     [](arc::Core &core) -> void {
         core.changeGame(core.getPrevGame());
     }},
    {arc::Event::CHANGE_GAME_R,
     [](arc::Core &core) -> void {
         core.changeGame(core.getNextGame());
     }},
    {arc::Event::CHANGE_LIB_L,
     [](arc::Core &core) -> void {
         core.changeDisplay(core.getPrevDisplay());
     }},
    {arc::Event::CHANGE_LIB_R,
     [](arc::Core &core) -> void {
         core.changeDisplay(core.getNextDisplay());
     }},
    {arc::Event::QUIT,
     [](arc::Core &core) -> void {
         core.setMode(arc::CoreMode::Quit);
     }},
    {arc::Event::RESTART,
     [](arc::Core &core) -> void {
         core.getIGame().get().ResetGame();
     }},
    {arc::Event::BACK_MENU,
     [](arc::Core &core) -> void {
         core.noMoreGame();
         core.setMode(arc::CoreMode::Menu);
     }},
};

// this method should just give the display method, window to the game
void arc::Core::handDisplay()
{
    if (this->mode == CoreMode::Game)
        this->game->DisplayGame(this->display->GetWindow().get());
    else
        this->menu.display(this->display->GetWindow());
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
