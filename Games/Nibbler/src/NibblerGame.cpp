/*
** EPITECH PROJECT, 2023
** src
** File description:
** NibblerGame
*/

#include <Nibbler/NibblerGame.hh>

void NibblerGame::move_snake_analyse(const arc::Vector &snake_head_position, int x_add, int y_add,
                                     Orient orient)
{
    if (m_map[snake_head_position.x + x_add] == "x") {
        if (m_map[snake_head_position.y + 1] == "x" && m_map[snake_head_position.y - 1] == "x")
            return;
        if (m_map[snake_head_position.y + 1] == "x") {
            m_snake.move_snake(snake_head_position.x, snake_head_position.y + 1, Orient::S);
            return;
        }
        if (m_map[snake_head_position.y - 1] == "x") {
            m_snake.move_snake(snake_head_position.x, snake_head_position.y + 1, Orient::N);
            return;
        }
    }
    if (m_map[snake_head_position.y + y_add] == "x") {
        if (m_map[snake_head_position.x + 1] == "x" && m_map[snake_head_position.x - 1] == "x")
            return;
        if (m_map[snake_head_position.x + 1] == "x") {
            m_snake.move_snake(snake_head_position.x + 1, snake_head_position.y, Orient::W);
            return;
        }
        if (m_map[snake_head_position.x - 1] == "x") {
            m_snake.move_snake(snake_head_position.x, snake_head_position.y + 1, Orient::E);
            return;
        }
    }
    if (m_map[snake_head_position.y + y_add] == "p" ||
        m_map[snake_head_position.x + x_add] == "p") {
        m_snake.expand_snake();
        m_snake.move_snake(snake_head_position.y + y_add, snake_head_position.x + x_add, orient);
        return;
    }
    if (m_snake.is_cell_snake(snake_head_position.x + x_add, snake_head_position.y + y_add)) {
        ResetGame();
    }
}

void NibblerGame::ResetGame()
{
    if (m_score.highscore < m_score.current_score)
        m_score.highscore = m_score.current_score;
    m_snake.reset_snake();
}

void NibblerGame::EventAnalisys(const arc::Event &event)
{
    const arc::Vector snake_head_position{m_snake.get_head_position()};

    if (event == arc::Event::UP)
        move_snake_analyse(snake_head_position, 0, -1, Orient::N);
    if (event == arc::Event::DOWN)
        move_snake_analyse(snake_head_position, 0, 1, Orient::S);
    if (event == arc::Event::RIGHT)
        move_snake_analyse(snake_head_position, 1, 0, Orient::E);
    if (event == arc::Event::LEFT)
        move_snake_analyse(snake_head_position, -1, 0, Orient::W);
}

void NibblerGame::SetSprite(arc::IDisplay &display)
{
    this->m_sprite = display.createSprite();
}

void NibblerGame::SetText(arc::IDisplay &display)
{
    this->m_text = display.createText();
}
