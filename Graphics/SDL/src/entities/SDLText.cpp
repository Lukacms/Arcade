/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLText
*/

#include "arcade/interfaces/IEntity.hh"
#include <SDL/entities/SDLText.hh>
#include <SDL/entities/SDLFont.hh>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_ttf.h>

/* Constructor && Destructor */

/* Methods */

void arc::SDLText::createEntity(std::string str)
{
    this->text = str;
}

void arc::SDLText::createEntity(arc::IEntity &entity)
{
    SDLFont *font = dynamic_cast<SDLFont *>(&entity);
    SDL_Color color = {0 ,0 ,0};

    if (font == nullptr)
        throw;
    this->m_text = TTF_RenderText_Solid(font->getFont(), this->text.c_str(), color);
}

void arc::SDLText::drawEntity(__attribute__((unused)) IWindow &window)
{
    SDL_Rect sprite = {this->entityRect.getLeft(), this->entityRect.getTop(),
                       this->entityRect.getWidth(), this->entityRect.getHeight()} ;
    SDL_Rect position = {this->entityPosition.getVectorX(), this->entityPosition.getVectorY(),
                        0, 0};

    // Dynamic cast on Window + Verif + throw if snot good
    //SDL_BlitSurface(this->m_surface, sprite, ,position);
}