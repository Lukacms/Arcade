/*
** EPITECH PROJECT, 2023
** src
** File description:
** SFMLDisplay
*/

#include "arcade/interfaces/IText.hh"
#include <SFML/Window/Event.hpp>
#include <arcade/interfaces/ADisplay.hh>
#include <arcade/interfaces/IWindow.hh>

struct EventLink {
        arc::Event s_event;
        sf::Keyboard::Key s_key_code;
};

namespace SFML_KEY
{
    constexpr const int BACKSPACE = 127;
}

class SFMLDisplay : public arc::ADisplay
{
    public:
        SFMLDisplay();
        SFMLDisplay(SFMLDisplay const &to_copy) = delete;
        SFMLDisplay(SFMLDisplay &&to_move) = default;
        ~SFMLDisplay() override = default;
        SFMLDisplay &operator=(SFMLDisplay const &to_copy) = delete;
        SFMLDisplay &operator=(SFMLDisplay &&to_move) = default;

        arc::Event GetEvent() final;
        std::unique_ptr<arc::IText> createText() final;
        std::unique_ptr<arc::ISprite> createSprite() final;

    private:
        arc::Event analyse_key_pressed();
        sf::Event m_event;
        std::vector<EventLink> m_event_list;
};
