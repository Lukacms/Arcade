/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLSprite
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <arcade/interfaces/AEntity.hh>
#include <arcade/interfaces/IWindow.hh>
#include <arcade/Geometry.hh>
#include <string>

namespace arc {

    class SFMLSprite : public AEntity {
        public:
            SFMLSprite();
            SFMLSprite(const SFMLSprite&);
            ~SFMLSprite() override;

            SFMLSprite &operator=(const SFMLSprite&);

            void createEntity(std::string str) final;
            void createEntity(IEntity &entity) final;
            void destroyEntity() final;
            void drawEntity(IWindow &window) final;

        protected:
            sf::Sprite m_sprite;
            arc::Rect m_rect;
    };
}
