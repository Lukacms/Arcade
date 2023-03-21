/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLSurface
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <arcade/interfaces/AEntity.hh>

namespace arc {
    class SDLSurface : public AEntity {
        public:
            SDLSurface();
            SDLSurface(const SDLSurface&);
            ~SDLSurface() override;

            SDLSurface &operator=(const SDLSurface&);

            void createEntity(std::string str) final;
            void createEntity(IEntity &entity) final;
            void destroyEntity() final;
            void drawEntity(IWindow &window) final;
            [[nodiscard]] SDL_Surface *getSurface() const;

        private:
            SDL_Surface *m_surface;
    };
}
