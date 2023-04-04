/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** NCursesSprite
*/

#pragma once

#include <arcade/interfaces/ISprite.hh>
#include <curses.h>

namespace arc
{

    class NCursesSprite : public ISprite
    {

        public:
            NCursesSprite() = default;
            NCursesSprite(char sprite);
            NCursesSprite(const NCursesSprite &) = default;
            ~NCursesSprite() override = default;

            NCursesSprite &operator=(const NCursesSprite &);

            void setSpriteColor(int red, int green, int blue) final;
            void moveSpritePosition(int pos_x, int pos_y) final;
            void setSpritePosition(int pos_x, int pos_y) final;
            void drawSprite(IWindow &window) final;
            [[nodiscard]] ISprite &getSprite() final;

        private:
            char m_sprite;
            int m_x;
            int m_y;
            arc::Color m_color = {0, 0, 0};
    };

} // namespace arc