/*
** EPITECH PROJECT, 2023
** opts
** File description:
** Opts
*/

#include <algorithm>
#include <arcade/Core.hh>
#include <arcade/Opts.hh>
#include <string>

// ctor / dtor

arc::Opts::Opts(std::string pstarting_display) : starting_display{std::move(pstarting_display)} {}

// static method

arc::Core arc::Opts::getOpts()
{
    try {
        this->loadLibs();
        this->loadStartingDisplay();
    } catch (arc::Opts::OptsException &e) {
        throw std::move(e);
    }
    return std::move(this->core);
}
