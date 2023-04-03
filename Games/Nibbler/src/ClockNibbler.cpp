/*
** EPITECH PROJECT, 2023
** src
** File description:
** ClockNibbler
*/

#include <Nibbler/ClockNibbler.hh>
#include <chrono>
#include <iostream>

std::chrono::duration<double> NibblerClock::getElapsedTime()
{
    this->updated = std::chrono::steady_clock::now();

    return updated - start;
}

double NibblerClock::getElapsedTimeInS()
{
    auto tmp = this->getElapsedTime();
    tmp.count();
    return tmp.count();
}

void NibblerClock::reset()
{
    this->start = std::chrono::steady_clock::now();
    this->updated = std::chrono::steady_clock::now();
}
