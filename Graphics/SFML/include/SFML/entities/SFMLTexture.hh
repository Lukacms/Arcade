/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLTexture
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <arcade/interfaces/AEntity.hh>

namespace arc
{

    class SFMLTexture : public AEntity {
        public:
            SFMLTexture();
            SFMLTexture(const SFMLTexture&);
            ~SFMLTexture() override;

            SFMLTexture &operator=(const SFMLTexture&);

            void createEntity(std::string str) final;
            void createEntity(IEntity &entity) final;
            void destroyEntity() final;
            void drawEntity(IWindow &window) final;
            sf::Texture &getTexture();

        protected:
            sf::Texture m_texture{};
    };
}
