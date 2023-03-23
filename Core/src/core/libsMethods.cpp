/*
** EPITECH PROJECT, 2023
** core
** File description:
** libsMethods
*/

#include "arcade/interfaces/IDisplay.hh"
#include "arcade/interfaces/IGame.hh"
#include <algorithm>
#include <arcade/Core.hh>
#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <typeinfo>

// ideal method :(
// TODO test again with classes implemented
/* void arc::Core::isGameOrGraphic(const std::string &filepath)
{
    void *handle = dlopen(filepath.c_str(), RTLD_LAZY);

    if (!handle)
        throw arc::Core::CoreException(DLOPEN_ERR.data());
    auto *reinterpret = reinterpret_cast<arc::IDisplay *>(handle);
    try {
        if (dynamic_cast<arc::IGame *>(reinterpret)) {
            this->shared_games.push_back(std::move(filepath));
        } else
            this->shared_displays.push_back(std::move(filepath));
    } catch (std::bad_cast &e) {
        throw arc::Core::CoreException(e.what());
    }
    dlclose(handle);
} */

void arc::Core::isGameOrGraphic(const std::string &filepath)
{
    for (auto display_filepath : DISPLAYS) {
        if (display_filepath == filepath) {
            this->shared_displays.push_back(filepath);
            return;
        }
    }
    for (auto game_filepath : GAMES) {
        if (game_filepath == filepath) {
            this->shared_games.push_back(filepath);
            return;
        }
    }
    throw arc::Core::CoreException(LIB_FORMAT_ERR.data());
}
