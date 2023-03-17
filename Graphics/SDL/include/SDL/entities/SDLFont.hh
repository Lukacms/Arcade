/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLFont
*/

#pragma once

#include <arcade/interfaces/AEntity.hh>
#include <SDL2/SDL_ttf.h>

namespace arc {

    constexpr int FONT_SIZE = 24;

    class SDLFont : public AEntity {
        public:
            SDLFont();
            SDLFont(const SDLFont&);
            ~SDLFont() override;

            SDLFont &operator=(const SDLFont&);

            void createEntity(std::string str) final;
            void createEntity(IEntity &entity) final;
            void destroyEntity() final;
            void drawEntity(IWindow &window) final;
            [[nodiscard]] TTF_Font *getFont() const;

        private:
            TTF_Font *m_font;
    };

}
