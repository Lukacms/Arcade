/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include <algorithm>
#include <arcade/Core.hh>
#include <arcade/Opts.hh>
#include <arcade/RuntimeExecption.hh>
#include <arcade/arcade.hh>
#include <iostream>
#include <string>

static void check_env()
{
    if (std::getenv("DISPLAY") == nullptr)
        throw arc::RuntimeExecption{"Arcade: No DISPLAY env variable"};
}

static int launch(std::string filepath)
{
    arc::Opts opts{std::move(filepath)};
    arc::Core core{};

    try {
        check_env();
        core = opts.getOpts();
        core.mainGameLoop();
    } catch (arc::Opts::OptsException &e) {
        std::cout << e.what() << "\n";
        return EPITECH_FAILURE;
    } catch (arc::Core::CoreException &e) {
        std::cout << e.what() << "\n";
        return EPITECH_FAILURE;
    } catch (arc::RuntimeExecption &e) {
        std::cout << e.what() << '\n';
        return EPITECH_FAILURE;
    }
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
