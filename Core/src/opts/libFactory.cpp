/*
** EPITECH PROJECT, 2023
** opts
** File description:
** libFactory
*/

#include <arcade/Core.hh>
#include <arcade/Opts.hh>
#include <dlfcn.h>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

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
    std::vector<std::string> displays = this->core.getSharedDisplays();

    if (!this->checkDisplay(displays))
        throw arc::Opts::OptsException(OPTS_WRONG_LIB.data());
    try {
        this->core.changeDisplay(this->starting_display);
    } catch (arc::Core::CoreException &e) {
        throw arc::Opts::OptsException(e.what());
    }
}

bool arc::Opts::checkDisplay(const std::vector<std::string> &displays)
{
    for (std::string display : displays)
        if (display == this->starting_display)
            return true;
    return false;
}
