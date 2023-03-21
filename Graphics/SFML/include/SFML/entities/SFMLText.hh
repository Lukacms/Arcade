/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLText
*/

#pragma once

#include <SFML/Graphics/Font.hpp>
#include <arcade/interfaces/AText.hh>

namespace arc {
    
    class SFMLText : public AText {
        public:
            SFMLText() = default;
            SFMLText(const SFMLText&) = default;
            SFMLText(SFMLText &&) = delete;
            ~SFMLText() override = default;
    
            SFMLText &operator=(const SFMLText&) = default;
            SFMLText &operator=(SFMLText &&);

            void destroyText() final;
            void drawText(IWindow &window) final;
            [[nodiscard]] IText &getText() final;

        private:
            sf::Font m_font;
    };

}