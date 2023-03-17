/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLFont
*/

#include <arcade/interfaces/IEntity.hh>
#include <SDL/entities/SDLFont.hh>
#include <SDL2/SDL_ttf.h>

/* Constructor && Destructor */

/* Methods */

void arc::SDLFont::createEntity(std::string str)
{
    this->m_font = TTF_OpenFont(str.c_str(), FONT_SIZE);
    if (this->m_font == NULL)
        throw;
}

void arc::SDLFont::createEntity(__attribute__((unused)) arc::IEntity &entity) {}

void arc::SDLFont::destroyEntity()
{
    if (this->m_font != NULL)
        TTF_CloseFont(this->m_font);
}

TTF_Font *arc::SDLFont::getFont() const
{
    return this->m_font;
}