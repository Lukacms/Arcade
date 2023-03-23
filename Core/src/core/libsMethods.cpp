/*
** EPITECH PROJECT, 2023
** core
** File description:
** libsMethods
*/

#include <algorithm>
#include <arcade/Core.hh>
#include <arcade/interfaces/IDisplay.hh>
#include <arcade/interfaces/IGame.hh>
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

void arc::Core::changeDisplay(const std::string &filepath)
{
    void *handle = nullptr;

    if (this->display)
        this->display.release();
    if (!(handle = dlopen(filepath.c_str(), RTLD_LAZY)))
        throw arc::Core::CoreException(LIB_LOADING_ERR.data());
    auto *loader =
        reinterpret_cast<std::unique_ptr<arc::IDisplay> (*)()>(dlsym(handle, LOAD_METHOD.data()));
    if (!loader)
        throw arc::Core::CoreException(LIB_OBJ_LOAD_ERR.data());
    this->display = loader();
}

void arc::Core::changeGame(const std::string &filepath)
{
    void *handle = nullptr;

    // NOTE if well understood, release the ownership of the pointer, so call the destructor
    // same for the above function
    if (this->game)
        this->game.release();
    if (!(handle = dlopen(filepath.c_str(), RTLD_LAZY)))
        throw arc::Core::CoreException(LIB_LOADING_ERR.data());
    auto *loader =
        reinterpret_cast<std::unique_ptr<arc::IGame> (*)()>(dlsym(handle, LOAD_METHOD.data()));
    this->game = loader();
}
