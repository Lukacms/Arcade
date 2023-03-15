/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ASprite
*/

#include "arcade/interfaces/entities/IEntity.hh"
#include <arcade/interfaces/entities/AEntity.hh>
#include <utility>

/* Constructor & Destructor */

/* Methods */

/**
 * Move the entity by the given vector.
 * @param vector The vector by which to move the entity.
 */
void arc::AEntity::moveEntity(arc::Vector vector)
{
    float current_x = this->entityPosition.getVectorX();
    float current_y = this->entityPosition.getVectorY();
    float add_x = vector.getVectorX();
    float add_y = vector.getVectorY();

    this->entityPosition.setVectorX(current_x + add_x);
    this->entityPosition.setVectorY(current_y + add_y);
}

/**
 * Set the entity by the given vector.
 * @param vector The vector by which to move the entity.
 */
void arc::AEntity::setPosition(arc::Vector vector)
{
    float new_x = vector.getVectorX();
    float new_y = vector.getVectorY();

    this->entityPosition.setVectorX(new_x);
    this->entityPosition.setVectorY(new_y);
}

/**
 * Get a reference to the entity as an IEntity object.
 * @return A reference to the entity as an IEntity object.
 */
arc::IEntity &arc::AEntity::getEntity()
{
    return *static_cast<arc::IEntity *>(this);
}
