/*
** EPITECH PROJECT, 2023
** src
** File description:
** main
*/

#include <arcade/arcade.hh>
#include <iostream>

int main(int argc, const char __attribute__((unused)) * argv[])
{
    if (argc != ARGS_REQUIRED) {
        std::cout << USAGE_MSG;
        return EPITECH_FAILURE;
    }
    return EPITECH_SUCCESS;
}
