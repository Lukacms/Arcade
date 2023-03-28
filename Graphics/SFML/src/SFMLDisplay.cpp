/*
** EPITECH PROJECT, 2023
** src
** File description:
** SFMLDisplay
*/

#include "SFML/SFMLDisplay.hh"
#include "SFML/SFMLWindow.hh"
#include "SFML/entities/SFMLSprite.hh"
#include "SFML/entities/SFMLText.hh"
#include "arcade/interfaces/ISprite.hh"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <algorithm>
#include <arcade/Opts.hh>
#include <exception>

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

    if (!dynamic_cast<SFMLWindow *>(m_window.get())) {
        throw arc::Opts{"SFML window cast error"};
    }
    auto *test = dynamic_cast<sf::RenderWindow *>(m_window.get());
    if (test->pollEvent(m_event)) {
        if (sf::Event::Closed)
            return arc::Event::QUIT;
        tmp = analyse_key_pressed();
        if (tmp != arc::Event::NONE)
            return tmp;
    }
    return arc::Event::NONE;
}

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
}

std::string SFMLDisplay::GetUserName()
{
    std::string name{};
    sf::Event event{};
    sf::Font font{};
    sf::Text text{};
    int tmp{-1};

    if (!font.loadFromFile("./graphics_assets/font.tff"))
        throw arc::Opts{"Cant load ./graphics_assets/font.tff"};
    if (!dynamic_cast<SFMLWindow *>(m_window.get()))
        throw arc::Opts{"SFML window cast error"};
    text.setFont(font);
    text.setPosition(400, 300);
    text.setScale(4, 4);
    auto *test = dynamic_cast<sf::RenderWindow *>(m_window.get());
    test->pollEvent(m_event);
    tmp = event.type;
    while (tmp != '\n') {
        if (tmp == SFML_KEY::BACKSPACE && !name.empty()) {
            test->clear();
            name.pop_back();
            text.setString(name);
            test->draw(text);
            test->display();
        }
        if (tmp >= 'a' && tmp <= 'z') {
            test->clear();
            name.push_back(tmp);
            text.setString(name);
            test->draw(text);
            test->display();
        }
        tmp = event.type;
    }
    if (name.empty()) {
        return std::string{"Arcade Sucks"};
    }
    return name;
}

std::unique_ptr<arc::IText> createText()
{
    return std::make_unique<arc::SFMLText>();
}

std::unique_ptr<arc::ISprite> createSprite()
{
    return std::make_unique<arc::SFMLSprite>();
}
