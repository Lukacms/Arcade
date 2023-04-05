/*
** EPITECH PROJECT, 2023
** src
** File description:
** SFMLDisplay
*/

#include <SFML/Graphics/Font.hpp>
#include <SFML/SFMLDisplay.hh>
#include <SFML/SFMLWindow.hh>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/entities/SFMLSprite.hh>
#include <SFML/entities/SFMLText.hh>
#include <algorithm>
#include <arcade/Opts.hh>
#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IWindow.hh>
#include <exception>
#include <memory>

/* Constructor && Destructor */

SFMLDisplay::SFMLDisplay()
{
    m_event = sf::Event{};

    m_event_list.push_back(EventLink{arc::Event::UP, sf::Keyboard::Up});
    m_event_list.push_back(EventLink{arc::Event::DOWN, sf::Keyboard::Down});
    m_event_list.push_back(EventLink{arc::Event::LEFT, sf::Keyboard::Left});
    m_event_list.push_back(EventLink{arc::Event::RIGHT, sf::Keyboard::Right});
    m_event_list.push_back(EventLink{arc::Event::QUIT, sf::Keyboard::Escape});
    m_event_list.push_back(EventLink{arc::Event::ENTER, sf::Keyboard::Enter});
    m_event_list.push_back(EventLink{arc::Event::CHANGE_GAME_L, sf::Keyboard::F1});
    m_event_list.push_back(EventLink{arc::Event::CHANGE_GAME_L, sf::Keyboard::F2});
    m_event_list.push_back(EventLink{arc::Event::CHANGE_LIB_L, sf::Keyboard::F3});
    m_event_list.push_back(EventLink{arc::Event::CHANGE_LIB_R, sf::Keyboard::F4});
    m_event_list.push_back(EventLink{arc::Event::RESTART, sf::Keyboard::R});
    m_event_list.push_back(EventLink{arc::Event::BACK_MENU, sf::Keyboard::Q});
    m_event_list.push_back(EventLink{arc::Event::BACKSPACE, sf::Keyboard::BackSpace});
    m_event_list.push_back(EventLink{arc::Event::A, sf::Keyboard::A});
    m_event_list.push_back(EventLink{arc::Event::B, sf::Keyboard::B});
    m_event_list.push_back(EventLink{arc::Event::C, sf::Keyboard::C});
    m_event_list.push_back(EventLink{arc::Event::D, sf::Keyboard::D});
    m_event_list.push_back(EventLink{arc::Event::E, sf::Keyboard::E});
    m_event_list.push_back(EventLink{arc::Event::F, sf::Keyboard::F});
    m_event_list.push_back(EventLink{arc::Event::G, sf::Keyboard::G});
    m_event_list.push_back(EventLink{arc::Event::H, sf::Keyboard::H});
    m_event_list.push_back(EventLink{arc::Event::I, sf::Keyboard::I});
    m_event_list.push_back(EventLink{arc::Event::J, sf::Keyboard::J});
    m_event_list.push_back(EventLink{arc::Event::K, sf::Keyboard::K});
    m_event_list.push_back(EventLink{arc::Event::L, sf::Keyboard::L});
    m_event_list.push_back(EventLink{arc::Event::M, sf::Keyboard::M});
    m_event_list.push_back(EventLink{arc::Event::N, sf::Keyboard::N});
    m_event_list.push_back(EventLink{arc::Event::O, sf::Keyboard::O});
    m_event_list.push_back(EventLink{arc::Event::P, sf::Keyboard::P});
    m_event_list.push_back(EventLink{arc::Event::Q, sf::Keyboard::Q});
    m_event_list.push_back(EventLink{arc::Event::R, sf::Keyboard::R});
    m_event_list.push_back(EventLink{arc::Event::S, sf::Keyboard::S});
    m_event_list.push_back(EventLink{arc::Event::T, sf::Keyboard::T});
    m_event_list.push_back(EventLink{arc::Event::U, sf::Keyboard::U});
    m_event_list.push_back(EventLink{arc::Event::V, sf::Keyboard::V});
    m_event_list.push_back(EventLink{arc::Event::W, sf::Keyboard::W});
    m_event_list.push_back(EventLink{arc::Event::X, sf::Keyboard::X});
    m_event_list.push_back(EventLink{arc::Event::Y, sf::Keyboard::Y});
    m_event_list.push_back(EventLink{arc::Event::Z, sf::Keyboard::Z});
    this->m_window = std::make_unique<SFMLWindow>(800, 600, "Arcade");
}

/* Methods */

arc::Event SFMLDisplay::analyse_key_pressed()
{
    auto lambda = [&](EventLink &event_link) -> bool {
        return event_link.s_key_code == m_event.key.code;
    };
    auto result = std::find_if(m_event_list.begin(), m_event_list.end(), lambda);
    if (result != std::end(m_event_list))
        return result->s_event;
    return arc::Event::NONE;
}

arc::Event SFMLDisplay::GetEvent()
{
    arc::Event tmp{arc::Event::NONE};
    SFMLWindow *nwin = dynamic_cast<SFMLWindow *>(m_window.get());

    if (nwin == nullptr)
        throw;
    while (nwin->GetWindow().pollEvent(m_event)) {
        if (sf::Event::Closed)
            return arc::Event::QUIT;
        if (m_event.type != sf::Event::EventType::KeyPressed)
            return arc::Event::NONE;
        tmp = analyse_key_pressed();
        if (tmp != arc::Event::NONE)
            return tmp;
    }
    return arc::Event::NONE;
}

std::unique_ptr<arc::IText> SFMLDisplay::createText()
{
    return std::make_unique<arc::SFMLText>();
}

std::unique_ptr<arc::ISprite> SFMLDisplay::createSprite()
{
    return std::make_unique<arc::SFMLSprite>();
}
