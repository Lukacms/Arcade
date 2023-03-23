/*
** EPITECH PROJECT, 2023
** opts
** File description:
** libFactory
*/

#include "arcade/Core.hh"
#include <arcade/Opts.hh>
#include <dlfcn.h>
#include <filesystem>
#include <iostream>

void arc::Opts::loadLibs()
{
    std::filesystem::path folder{LIBS_PATHS};

    for (auto file : std::filesystem::directory_iterator(folder)) {
        try {
            this->core.isGameOrGraphic(file.path());
        } catch (arc::Core::CoreException &e) {
            throw arc::Opts::OptsException(e.what());
        }
    }
}

void arc::Opts::loadStartingDisplay()
{
    try {
        this->core.changeDisplay(this->starting_display);
    } catch (arc::Core::CoreException &e) {
        throw arc::Opts::OptsException(e.what());
    }
}
