/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include <algorithm>
#include <arcade/Core.hh>
#include <arcade/Opts.hh>
#include <arcade/arcade.hh>
#include <iostream>
#include <string>

static int launch(std::string filepath)
{
    arc::Opts opts{std::move(filepath)};
    arc::Core core{};

    try {
        core = opts.getOpts();
    } catch (arc::Opts::OptsException &e) {
        std::cout << e.what() << "\n";
        return EPITECH_FAILURE;
    }
    while(1);
    return EPITECH_SUCCESS;
}

int main(int argc, const char *argv[])
{
    if (argc != ARGS_REQUIRED) {
        std::cout << USAGE_MSG;
        return EPITECH_FAILURE;
    }
    return launch(std::string{argv[1]});
}
