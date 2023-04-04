/*
** EPITECH PROJECT, 2023
** Core
** File description:
** optTest
*/

#include <arcade/Opts.hh>
#include <catch2/catch.hpp>

TEST_CASE("Basic testing for Opts", "oui")
{
    arc::Opts opts{"."};

    try {
        opts.getOpts();
    } catch (arc::Opts::OptsException &e) {
        REQUIRE(e.what() == CORE_NOLIBS);
    }
}
