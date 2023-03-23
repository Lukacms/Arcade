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

// TODO methods to load shared libraries
// NOTE need to make some sort of factory ?

void arc::Opts::loadLibs()
{
    std::filesystem::path folder{LIBS_PATHS};

    for (auto file : std::filesystem::directory_iterator(folder)) {
        try {
            // this->core.addSharedLib(file.path());
            this->core.isGameOrGraphic(file.path());
        } catch (arc::Core::CoreException &e) {
            throw arc::Opts::OptsException(e.what());
        }
    }
}

void arc::Opts::loadStartingDisplay() {}
