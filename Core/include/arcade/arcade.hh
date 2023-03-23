/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** arcade
*/

#pragma once

#include <string_view>
constexpr int const EPITECH_FAILURE = 84;
constexpr int const EPITECH_SUCCESS = 0;

constexpr std::string_view USAGE_MSG{"USAGE: ./arcade [library]\n\
    [library] is the path to the startup library to use. It may change at runtime\n"};

constexpr int const ARGS_REQUIRED = 2;
