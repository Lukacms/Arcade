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
#include <iostream>
#include <memory>

/* Constructor && Destructor */

SFMLDisplay::SFMLDisplay()
{
    m_event = sf::Event{};

    m_event_list.push_back(EventLink{arc::Event::UP, sf::Keyboard::Up});
    m_event_list.push_back(EventLink{arc::Event::DOWN, sf::Keyboard::Down});
    m_event_list.push_back(EventLink{arc::Event::LEFT, sf::Keyboard::Left});
    m_event_list.push_back(EventLink{arc::Event::RIGHT, sf::Keyboard::Right});
    m_event_list.push_back(EventLink{arc::Event::QUIT, sf::Keyboard::X});
    m_event_list.push_back(EventLink{arc::Event::ENTER, sf::Keyboard::Enter});
    m_event_list.push_back(EventLink{arc::Event::CHANGE_GAME_L, sf::Keyboard::F1});
    m_event_list.push_back(EventLink{arc::Event::CHANGE_GAME_L, sf::Keyboard::F2});
    m_event_list.push_back(EventLink{arc::Event::CHANGE_LIB_L, sf::Keyboard::F3});
    m_event_list.push_back(EventLink{arc::Event::CHANGE_LIB_R, sf::Keyboard::F4});
    m_event_list.push_back(EventLink{arc::Event::RESTART, sf::Keyboard::R});
    m_event_list.push_back(EventLink{arc::Event::BACK_MENU, sf::Keyboard::Q});
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
    if (nwin->GetWindow().pollEvent(m_event)) {
        if (sf::Event::Closed)
            return arc::Event::QUIT;
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
