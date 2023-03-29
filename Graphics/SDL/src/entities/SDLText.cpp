/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLText
*/

#include <SDL/SDLWindow.hh>
#include <SDL/entities/SDLText.hh>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>

/* Constructor && Destructor */

arc::SDLText::~SDLText()
{
    if (this->m_font != nullptr)
        TTF_CloseFont(this->m_font);
}

/* Methods */

void arc::SDLText::setText(std::string str)
{
    this->m_text = str;
}

void arc::SDLText::setFont(const std::string &font)
{
    this->m_font = TTF_OpenFont(font.c_str(), 24);
    if (this->m_font == nullptr)
        throw;
}

void arc::SDLText::setTextColor(int red, int green, int blue)
{
    this->m_color.red = red;
    this->m_color.green = green;
    this->m_color.blue = blue;
}

void arc::SDLText::setTextPosition(int pos_x, int pos_y)
{
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

void arc::SDLText::drawText(IWindow &window)
{
    SDLWindow *nwin = dynamic_cast<SDLWindow *>(&window);
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Color color = {static_cast<Uint8>(this->m_color.red),
                       static_cast<Uint8>(this->m_color.green),
                       static_cast<Uint8>(this->m_color.blue)};
    SDL_Rect rect;

    if (nwin == nullptr)
        throw;
    renderer = nwin->GetRenderer();
    rect.w = 40;
    rect.h = 30;
    rect.x *= rect.w;
    rect.y *= rect.h;
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
