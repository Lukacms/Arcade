/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLText
*/

#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <arcade/interfaces/IWindow.hh>
#include <arcade/interfaces/AEntity.hh>

namespace arc {

    class SFMLText : public AEntity {
        public:
            SFMLText();
            SFMLText(const SFMLText &);
            ~SFMLText() override;

            SFMLText &operator=(const SFMLText &);

            void createEntity(std::string str) final;
            void createEntity(IEntity &entity) final;
            void destroyEntity() final;
            void drawEntity(IWindow &window) final;
            void setFont(sf::Font &font);

        private:
            sf::Text m_text;
    };
}
