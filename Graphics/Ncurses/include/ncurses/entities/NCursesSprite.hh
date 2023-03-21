/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesSprite
*/

#pragma once

#include <arcade/interfaces/ASprite.hh>
#include <curses.h>

namespace arc {

        class NCursesSprite : public ASprite {

        public:
            NCursesSprite();
            NCursesSprite(const NCursesSprite&);
            ~NCursesSprite() override;

            NCursesSprite &operator=(const NCursesSprite&);

            void createSprite(const std::string &str);
            void createSprite(ISprite &sprite) final;
            void destroySprite() final;
            void drawSprite(IWindow &window) final;

        private:
            char m_sprite;
    };

}