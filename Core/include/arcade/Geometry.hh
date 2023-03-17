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

    class Rect {
        public:
            Rect(int width, int height, int top, int left);
            Rect(const Rect&);
            ~Rect();

            Rect &operator=(const Rect&);

            [[nodiscard]] int getWidth() const;
            [[nodiscard]] int getHeight() const;
            [[nodiscard]] int getTop() const;
            [[nodiscard]] int getLeft() const;
            int setWidth(int new_width);
            int setHeight(int new_height);
            int setTop(int new_top);
            int setLeft(int new_left);

        private:
            int width;
            int height;
            int top;
            int left;
    };
}
