/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SFMLText
*/

#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IText.hh>
#include <string>

namespace arc
{

    class SFMLText : public IText
    {
        public:
            SFMLText() = default;
            SFMLText(const SFMLText &) = default;
            SFMLText(SFMLText &&) = delete;
            ~SFMLText() override = default;

            SFMLText &operator=(const SFMLText &) = default;
            SFMLText &operator=(SFMLText &&);

            void setText(std::string str) final;
            void setFont(const std::string &font) final;
            void setTextColor(int red, int green, int blue) final;
            void setTextPosition(int pos_x, int pos_y) final;
            void drawText(IWindow &window) final;
            [[nodiscard]] IText &getText() final;

        private:
            sf::Text m_text;
            sf::Font m_font;
            int pos_x;
            int pos_y;
    };

} // namespace arc