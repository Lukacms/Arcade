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
#include <sys/types.h>

TEST_CASE("Basic testing for Opts", "directory")
{
    arc::Opts opts{"."};

    try {
        opts.getOpts();
    } catch (arc::Opts::OptsException &e) {
        REQUIRE(e.what() == std::string{".: cannot read file data: Is a directory"});
    }
}

TEST_CASE("Basic testing for Opts with an invalid file")
{
    arc::Opts opts{"./ieloqhd"};

    try {
        opts.getOpts();
    } catch (arc::Opts::OptsException &e) {
        REQUIRE(
            e.what() ==
            std::string{"./ieloqhd: cannot open shared object file: No such file or directory"});
    }
}

TEST_CASE("testing with good library", "loader")
{
    arc::Opts opts{"./lib/arcade_ncurses.so"};
    arc::Core core;

    try {
        core = opts.getOpts();
    } catch (arc::Opts::OptsException &e) {
        REQUIRE(e.what() == LIB_FORMAT_ERR);
    }
    REQUIRE(core.getSharedDisplays() == DISPLAYS);
    REQUIRE(core.getSharedGames() == GAMES);
}

TEST_CASE("basic things")
{
    arc::Opts opts{"./lib/arcade_sdl2.so"};
    arc::Core core;

    try {
        core = opts.getOpts();
    } catch (arc::Opts::OptsException &e) {
        REQUIRE(1 == 2);
    }
    REQUIRE(core.getMode() == arc::CoreMode::Menu);
}
