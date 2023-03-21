/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLText
*/

#include <SDL/entities/SDLText.hh>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <SDL/SDLWindow.hh>

/* Constructor && Destructor */

/* Methods */

void arc::SDLText::destroyText()
{
    TTF_CloseFont(this->m_font);
}

void arc::SDLText::drawText(IWindow &window)
{
    SDLWindow *nwin = dynamic_cast<SDLWindow *>(&window);
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Color color = {255, 255, 255};
    SDL_Rect rect;

    if (nwin == nullptr)
        throw;
    renderer = nwin->GetRenderer();
    rect.x = this->m_position.getVectorX();
    rect.y = this->m_position.getVectorY();
    rect.w = 100;
    rect.h = 100;
    surface = TTF_RenderText_Solid(this->m_font, this->m_text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}


arc::IText &arc::SDLText::getText()
{
    return *this;
}
