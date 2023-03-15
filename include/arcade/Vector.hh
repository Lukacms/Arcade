/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** Vector
*/

#pragma once

#include <utility>

namespace arc {

    class Vector {
        public:
            Vector(float pos_x, float pos_y);
            Vector(const Vector&);
            ~Vector();
            Vector &operator=(const Vector&);

            [[nodiscard]] float getVectorX() const;
            [[nodiscard]] float getVectorY() const;
            void setVectorX(float new_point);
            void setVectorY(float new_point);

        private:
            float x;
            float y;
    };
}
