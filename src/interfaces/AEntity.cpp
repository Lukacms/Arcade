/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ASprite
*/

#include <arcade/interfaces/AEntity.hh>
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
 * Set position of the entity by the given vector.
 * @param position The vector by which to move the entity.
 */
void arc::AEntity::setPosition(arc::Vector position)
{
    this->entityPosition.setVectorX(position.getVectorX());
    this->entityPosition.setVectorY(position.getVectorY());
}

/**
 * Set the entity size by the given vector
 * @param size The vector which represents size.
 */
void arc::AEntity::setSize(arc::Vector size)
{
    this->entityPosition.setVectorX(size.getVectorX());
    this->entityPosition.setVectorY(size.getVectorY());
}

/**
 * Set the entity rect by the given rectangle
 * @param rectangle The rectangle which represents rect.
 */
void arc::AEntity::setRectangle(arc::Rect rectangle)
{
    this->entityRect.setWidth( rectangle.getWidth());
    this->entityRect.setHeight(rectangle.getHeight());
    this->entityRect.setTop(rectangle.getTop());
    this->entityRect.setLeft(rectangle.getLeft());
}

/**
 * Get a reference to the entity as an IEntity object.
 * @return A reference to the entity as an IEntity object.
 */
arc::IEntity &arc::AEntity::getEntity()
{
    return *static_cast<arc::IEntity *>(this);
}
