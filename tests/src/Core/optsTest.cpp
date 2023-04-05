/*
** EPITECH PROJECT, 2023
** Core
** File description:
** optTest
*/

#include "arcade/Core.hh"
#include <arcade/Opts.hh>
#include <catch2/catch.hpp>
#include <string>

TEST_CASE("Basic testing for Opts", "oui")
{
    arc::Opts opts{"."};

    try {
        opts.getOpts();
    } catch (arc::Opts::OptsException &e) {
        REQUIRE(e.what() == std::string{".: cannot read file data: Is a directory"});
    }
}

TEST_CASE("testing with good library", "oui")
{
    arc::Opts opts{"./lib/arcade_ncurses.so"};
    arc::Core core;

    try {
        core = opts.getOpts();
    } catch (arc::Opts::OptsException &e) {
        REQUIRE(e.what() == LIB_FORMAT_ERR);
    }
    REQUIRE(core.getSharedDisplays() == DISPLAYS);
}
