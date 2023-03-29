/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLSprite
*/

#include <SDL/SDLWindow.hh>
#include <SDL/entities/SDLSprite.hh>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

/* Constructor && Destructor */

arc::SDLSprite::SDLSprite()
{
    m_sprite.x = 0;
    m_sprite.y = 0;
    m_sprite.w = 40;
    m_sprite.h = 30;
}

/* Methods */

void arc::SDLSprite::setSpritePosition(int pos_x, int pos_y)
{
    this->m_sprite.x = pos_x;
    this->m_sprite.y = pos_y;
}

void arc::SDLSprite::setSpriteColor(int red, int green, int blue)
{
    this->m_color.red = red;
    this->m_color.green = green;
    this->m_color.blue = blue;
}

void arc::SDLSprite::moveSpritePosition(int pos_x, int pos_y)
{
    this->m_sprite.x += pos_x;
    this->m_sprite.y += pos_y;
}

void arc::SDLSprite::drawSprite(IWindow &window)
{
    SDLWindow *nwin = dynamic_cast<SDLWindow *>(&window);
    SDL_Renderer *renderer;

    if (nwin == nullptr)
        throw;
    renderer = nwin->GetRenderer();
    SDL_SetRenderDrawColor(renderer, this->m_color.red, this->m_color.green, this->m_color.blue,
                           SDL_ALPHA_OPAQUE);
    this->m_sprite.x *= this->m_sprite.w;
    this->m_sprite.y *= this->m_sprite.h;
    SDL_RenderFillRect(renderer, &this->m_sprite);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
}

arc::ISprite &arc::SDLSprite::getSprite()
{
    return *this;
}