/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLSprite
*/

#include <SDL/entities/SDLSprite.hh>
#include <SDL/SDLWindow.hh>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

/* Constructor && Destructor */

/* Methods */

void arc::SDLSprite::createSprite(const std::string &str) {}

void arc::SDLSprite::createSprite(ISprite &sprite) {}

void arc::SDLSprite::destroySprite() {}

void arc::SDLSprite::drawSprite(IWindow &window)
{
    SDLWindow *nwin = dynamic_cast<SDLWindow *>(&window);
    SDL_Renderer *renderer;

    if (nwin == nullptr)
        throw;
    renderer = nwin->GetRenderer();
    this->m_sprite.x = this->m_position.getVectorX();
    this->m_sprite.y = this->m_position.getVectorY();
    this->m_sprite.w = this->m_size.getVectorX();
    this->m_sprite.h = this->m_size.getVectorY();
    SDL_SetRenderDrawColor(renderer, this->m_color.red,
        this->m_color.green, this->m_color.blue, 1);
    SDL_RenderFillRect(renderer, &this->m_sprite);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    SDL_RenderPresent(renderer);
}