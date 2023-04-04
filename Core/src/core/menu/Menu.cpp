/*
** EPITECH PROJECT, 2023
** menu
** File description:
** Menu
*/

#include <arcade/core/Menu.hh>
#include <iostream>
#include <string>

void arc::Menu::EventAnalisys(const arc::Event &event)
{
    if (m_state == MenuState::SELECT_NOM) {
        select_nom(event);
        return;
    }
    if (event == Event::UP)
        move_up();
    if (event == Event::DOWN)
        move_down();
    if (event == Event::ENTER) {
        enter_info();
        std::cout << "enter" << '\n';
    }
}

void arc::Menu::DisplayGame(IWindow &window)
{
    window.UpdateWindow();
    m_text->setFont("./assets/font/arcade.ttf");
    if (m_state != MenuState::SELECT_NOM) {
        for (size_t iterator = 0; iterator < m_graphic_lib.size(); iterator += 1) {
            m_text->setTextPosition(GRAPHIC_POSITION.x,
                                    GRAPHIC_POSITION.y + static_cast<int>(iterator));
            m_text->setTextColor(TEXT_COLOR_MENU.red, TEXT_COLOR_MENU.green, TEXT_COLOR_MENU.blue);
            m_text->setText(m_graphic_lib[iterator]);
            m_text->drawText(window);
        }
        for (size_t iterator = 0; iterator < m_game_lib.size(); iterator++) {
            m_text->setTextPosition(GAME_POSITION.x, GAME_POSITION.y + static_cast<int>(iterator));
            m_text->setTextColor(TEXT_COLOR_MENU.red, TEXT_COLOR_MENU.green, TEXT_COLOR_MENU.blue);
            m_text->setText(m_game_lib[iterator]);
            m_text->drawText(window);
        }
        m_text->setTextPosition(TITLE_POSTION.x, TITLE_POSTION.y);
        m_text->setTextColor(TEXT_COLOR_MENU.red, TEXT_COLOR_MENU.green, TEXT_COLOR_MENU.blue);
        m_text->setText("ARCADE");
        m_text->drawText(window);
        m_text->setTextPosition(m_cursor_tile.x_coord, m_cursor_tile.y_coord);
        m_text->setTextColor(255, 0, 0);
        m_text->setText(">");
        m_text->drawText(window);
    } else {
        m_text->setTextPosition(6, 0);
        m_text->setTextColor(TEXT_COLOR_MENU.red, TEXT_COLOR_MENU.green, TEXT_COLOR_MENU.blue);
        m_text->setText("ENTER NAME PLEASE:");
        m_text->drawText(window);
        m_text->setTextPosition(NAME_POSTION.x, NAME_POSTION.y);
        m_text->setTextColor(TEXT_COLOR_MENU.red, TEXT_COLOR_MENU.green, TEXT_COLOR_MENU.blue);
        m_text->setText(m_name);
        m_text->drawText(window);
    }
    window.OpenWindow();
}

void arc::Menu::ResetGame() {}

void arc::Menu::PlayGame() {}

void arc::Menu::InitGame() {}

void arc::Menu::SetSprite(arc::IDisplay &display)
{
    if (this->m_sprite)
        this->m_sprite.release();
    this->m_sprite = display.createSprite();
}

void arc::Menu::SetText(arc::IDisplay &display)
{
    if (this->m_text)
        this->m_text.release();
    this->m_text = display.createText();
}

[[nodiscard]] std::string arc::Menu::get_lib_graph() const
{
    return m_graphic_lib[m_player_selection.index_lib_grah];
}

[[nodiscard]] std::string arc::Menu::get_lib_game() const
{
    return m_game_lib[m_player_selection.index_lib_game];
}

void arc::Menu::move_up()
{
    if (m_cursor_tile.y_coord > CURSOR_BASE_POSITION.y)
        m_cursor_tile.y_coord--;
}

void arc::Menu::move_down()
{
    if (m_cursor_tile.y_coord < CURSOR_BASE_POSITION.y + static_cast<int>(m_graphic_lib.size()))
        m_cursor_tile.y_coord++;
}

void arc::Menu::enter_info()
{
    if (m_state == MenuState::SELECT_GAME) {
        m_state = MenuState::SELECT_LIB;
        m_cursor_tile.x_coord = CURSOR_BASE_POSITION.x;
        m_cursor_tile.y_coord = CURSOR_BASE_POSITION.y;
    }
    if (m_state == MenuState::SELECT_GAME) {
        m_state = MenuState::SELECT_LIB;
        m_cursor_tile.x_coord = GAME_POSITION.x - 1;
        m_cursor_tile.y_coord = CURSOR_BASE_POSITION.y;
    }
}

void arc::Menu::select_nom(const arc::Event &event)
{
    std::cout << m_name << '\n';
    if (event == arc::Event::ENTER) {
        m_state = MenuState::SELECT_LIB;
        return;
    }
    if (event == arc::Event::BACKSPACE)
        if (!m_name.empty())
            m_name.pop_back();
    if (event == arc::Event::A)
        m_name.push_back('a');
    if (event == arc::Event::B)
        m_name.push_back('b');
    if (event == arc::Event::C)
        m_name.push_back('c');
    if (event == arc::Event::D)
        m_name.push_back('d');
    if (event == arc::Event::E)
        m_name.push_back('e');
    if (event == arc::Event::F)
        m_name.push_back('f');
    if (event == arc::Event::G)
        m_name.push_back('g');
    if (event == arc::Event::H)
        m_name.push_back('h');
    if (event == arc::Event::I)
        m_name.push_back('i');
    if (event == arc::Event::J)
        m_name.push_back('j');
    if (event == arc::Event::K)
        m_name.push_back('k');
    if (event == arc::Event::L)
        m_name.push_back('l');
    if (event == arc::Event::M)
        m_name.push_back('m');
    if (event == arc::Event::N)
        m_name.push_back('n');
    if (event == arc::Event::O)
        m_name.push_back('o');
    if (event == arc::Event::P)
        m_name.push_back('p');
    if (event == arc::Event::Q)
        m_name.push_back('q');
    if (event == arc::Event::R)
        m_name.push_back('r');
    if (event == arc::Event::S)
        m_name.push_back('s');
    if (event == arc::Event::T)
        m_name.push_back('t');
    if (event == arc::Event::U)
        m_name.push_back('u');
    if (event == arc::Event::V)
        m_name.push_back('v');
    if (event == arc::Event::W)
        m_name.push_back('w');
    if (event == arc::Event::X)
        m_name.push_back('x');
    if (event == arc::Event::Y)
        m_name.push_back('y');
    if (event == arc::Event::Z)
        m_name.push_back('z');
}

void arc::Menu::set_lib_graph(std::vector<std::string> &graph)
{
    m_graphic_lib = graph;
}

void arc::Menu::set_lib_game(std::vector<std::string> &game)
{
    m_game_lib = game;
}
