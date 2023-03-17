/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLSurface
*/

#include "SDL/entities/SDLSurface.hh"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>

/* Contrustor && Destructor */

/* Methods */

void arc::SDLSurface::createEntity(std::string str)
{
    this->m_surface = IMG_Load(str.c_str());

    if (this->m_surface == NULL)
        throw;
}

void arc::SDLSurface::createEntity(__attribute__((unused))  arc::IEntity &entity) {}

void arc::SDLSurface::destroyEntity()
{
    SDL_FreeSurface(this->m_surface);
    this->m_surface = NULL;
}

void arc::SDLSurface::drawEntity(IWindow &window)
{
    SDL_Rect sprite = {this->entityRect.getLeft(), this->entityRect.getTop(),
                       this->entityRect.getWidth(), this->entityRect.getHeight()} ;
    SDL_Rect position = {this->entityPosition.getVectorX(), this->entityPosition.getVectorY(),
                        0, 0};

    // Dynamic cast on Window + Verif + throw if snot good
    //SDL_BlitSurface(this->m_surface, sprite, ,position);
}
