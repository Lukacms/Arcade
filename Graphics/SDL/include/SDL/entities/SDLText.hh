/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLText
*/

#pragma once

#include <SDL2/SDL_surface.h>
#include <arcade/interfaces/AEntity.hh>
#include <SDL2/SDL_ttf.h>
#include <string>

namespace arc {

    class SDLText : public AEntity {
        public:
            SDLText();
            SDLText(const SDLText&);
            ~SDLText() override;

            SDLText &operator=(const SDLText&);

            void createEntity(std::string str) final;
            void createEntity(IEntity &entity) final;
            void destroyEntity() final;
            void drawEntity(IWindow &window) final;
            [[nodiscard]] SDL_Surface *getText() const;

        private:
            SDL_Surface *m_text;
            std::string text{};
    };
}