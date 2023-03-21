/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AText
*/

#pragma once

#include <arcade/interfaces/IText.hh>

namespace arc {

    class AText : public IText {
        public:
            AText();
            AText(const AText &) = default;
            AText(AText &&) = delete;
            ~AText() override = default;
    
            AText &operator=(const AText &) = default;
            AText &operator=(AText &&);

            void createText(std::string str) final;
            void setPosition(arc::Vector vector) final;
            void setSize(int size) final;

        protected:
            std::string m_text;
            arc::Vector m_position;
            int m_size;

    };

}
