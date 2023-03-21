/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** ASprite
*/

#pragma once

#include <arcade/Geometry.hh>
#include <arcade/interfaces/ISprite.hh>

namespace arc {

    class ASprite : public ISprite {
        public:
            ASprite();
            ~ASprite() override = default;

            void moveSprite(arc::Vector vector) final;
            void setPosition(arc::Vector vector) final;
            void setSize(arc::Vector vector) final;
            void setRectangle(arc::Rect rect) final;
            void setColor(int red, int green, int blue) final;

        protected:
            arc::Vector m_position;
            arc::Vector m_size;
            arc::Rect m_rectangle;
            arc::Color m_color;
    };
}
