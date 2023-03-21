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
            Vector(int pos_x, int pos_y);
            Vector(const Vector&);
            ~Vector();

            Vector &operator=(const Vector&);
            Vector &operator+=(const Vector&);

            [[nodiscard]] int getVectorX() const;
            [[nodiscard]] int getVectorY() const;
            void setVectorX(int new_point);
            void setVectorY(int new_point);

        private:
            int x;
            int y;
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
