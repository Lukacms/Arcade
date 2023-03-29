/*
** EPITECH PROJECT, 2023
** core
** File description:
** CoreClock
*/

#include <arcade/core/CoreClock.hh>
#include <chrono>
#include <iostream>

std::chrono::duration<double> arc::CoreClock::getElapsedTime()
{
    this->updated = std::chrono::steady_clock::now();

    return updated - start;
}

double arc::CoreClock::getElapsedTimeInS()
{
    return this->getElapsedTime().count();
}

/**
 * reset the clock
 */
void arc::CoreClock::reset()
{
    this->start = std::chrono::steady_clock::now();
    this->updated = std::chrono::steady_clock::now();
}
