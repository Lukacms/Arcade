/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLSprite
*/

#pragma once

#include <arcade/interfaces/ISprite.hh>
#include <SFML/Graphics/RectangleShape.hpp>
#include <string>

namespace arc {

    class SFMLSprite : public ISprite {

        public:
            SFMLSprite() = default;
            SFMLSprite(const SFMLSprite&) = default;
            SFMLSprite(SFMLSprite &&) = delete;
            ~SFMLSprite() override = default;

            SFMLSprite &operator=(const SFMLSprite&) = default;
            SFMLSprite &operator=(SFMLSprite &&) = delete;

            void setSpriteColor(int red, int green, int blue) final;
            void moveSpritePosition(int pos_x, int pos_y) final;
            void setSpritePosition(int pos_x, int pos_y) final;
            void drawSprite(IWindow &window) final;
            [[nodiscard]]ISprite &getSprite() final;

        private:
            sf::RectangleShape m_sprite;
    };

}