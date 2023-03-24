/*
** EPITECH PROJECT, 2023
** src
** File description:
** Nibbler
*/

#include <Nibbler/Nibbler.hh>

void Snake::move_snake(int x_coord, int y_coord, Orient orientation)
{
    m_snake_tail.coord.x = m_snake_body[m_snake_body.size() - 1].coord.x;
    m_snake_tail.coord.y = m_snake_body[m_snake_body.size() - 1].coord.y;

    for (int i = m_snake_body.size() - 1; i >= 1; i--) {
        m_snake_body[i].coord.x = m_snake_body[i - 1].coord.x;
        m_snake_body[i].coord.y = m_snake_body[i - 1].coord.y;
        m_snake_body[i].orientation = m_snake_body[i - 1].orientation;
    }
    m_head_snake.coord.x = x_coord;
    m_head_snake.coord.y = y_coord;
    m_head_snake.orientation = orientation;
}

void Snake::expand_snake(int x_coord, int y_coord, Orient orientation)
{
    m_snake_body.emplace_back(
        Tile{{m_snake_tail.coord.x, m_snake_tail.coord.y}, m_snake_tail.orientation});
    m_snake_tail.coord.x = x_coord;
    m_snake_tail.coord.y = y_coord;
    m_snake_tail.orientation = orientation;
}

void Snake::reset_snake()
{
    m_head_snake.coord.x = 0;
    m_head_snake.coord.y = 0;
    m_snake_body.clear();
    m_snake_body.emplace_back(Tile{{1, 0}, Orient::NONE});
    m_snake_tail.coord.x = 2;
    m_snake_tail.coord.y = 0;
}

arc::Vector Snake::get_head_position() const
{
    return m_head_snake.coord;
}
