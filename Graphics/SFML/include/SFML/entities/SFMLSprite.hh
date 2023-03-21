/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLSprite
*/

#pragma once

#include <arcade/interfaces/ASprite.hh>
#include <SFML/Graphics/RectangleShape.hpp>
#include <string>

namespace arc {

    class SFMLSprite : public ASprite {

        public:
            SFMLSprite();
            SFMLSprite(const SFMLSprite&);
            ~SFMLSprite() override;

            SFMLSprite &operator=(const SFMLSprite&);

            void createSprite(const std::string &str);
            void createSprite(ISprite &sprite) final;
            void destroySprite() final;
            void drawSprite(IWindow &window) final;

        private:
            sf::RectangleShape m_sprite;
    };

}