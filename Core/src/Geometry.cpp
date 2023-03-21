/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Geometry
*/

#include <arcade/Geometry.hh>

/* Constructor && Destructor */

/* Operators */

arc::Vector &arc::Vector::operator+=(const Vector &vector)
{
    this->setVectorX(this->x + vector.getVectorX());
    this->setVectorY(this->y + vector.getVectorY());
    return (*this);
}

/* Methods */
