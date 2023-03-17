/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AEntity
*/

#include "arcade/interfaces/IEntity.hh"
#include <arcade/interfaces/AEntity.hh>

/* Constructor && Destructor */

/* Methods */

void arc::AEntity::moveEntity(arc::Vector vector)
{
    float pos_x = this->entityPosition.getVectorX();
    float pos_y = this->entityPosition.getVectorY();

    pos_x += vector.getVectorX();
    pos_y += vector.getVectorY();
    this->entityPosition.setVectorX(pos_x);
    this->entityPosition.setVectorY(pos_y);
}

void arc::AEntity::setPosition(arc::Vector position)
{
    this->entityPosition = position;
}

void arc::AEntity::setSize(arc::Vector size)
{
    this->entitySize = size;
}

void arc::AEntity::setRectangle(arc::Rect rectangle)
{
    this->entityRect = rectangle;
}

arc::IEntity &arc::AEntity::getEntity()
{
    return static_cast<IEntity &>(*this);
}
