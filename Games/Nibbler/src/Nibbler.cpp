/*
** EPITECH PROJECT, 2023
** src
** File description:
** Nibbler
*/

#include <Nibbler/Nibbler.hh>
#include <algorithm>
#include <bits/ranges_algo.h>

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

void Snake::expand_snake()
{
    m_snake_body.emplace_back(
        Tile{{m_snake_tail.coord.x, m_snake_tail.coord.y}, m_snake_tail.orientation});
    m_snake_tail.coord.x = 0;
    m_snake_tail.coord.y = 0;
    m_snake_tail.orientation = Orient::NONE;
}

void Snake::reset_snake()
{
    m_head_snake.coord.x = 4;
    m_head_snake.coord.y = POS_SNAKE_BASE_X;
    m_head_snake.orientation = Orient::E;
    m_snake_body.clear();
    m_snake_body.emplace_back(Tile{{3, POS_SNAKE_BASE_X}, Orient::E});
    m_snake_body.emplace_back(Tile{{2, POS_SNAKE_BASE_X}, Orient::E});
    m_snake_tail.coord.x = 1;
    m_snake_tail.coord.y = POS_SNAKE_BASE_X;
    m_snake_tail.orientation = Orient::E;
}

arc::Vector Snake::get_head_position() const
{
    return m_head_snake.coord;
}

bool Snake::is_cell_snake(int x_coord, int y_coord)
{
    if (x_coord == m_snake_tail.coord.x && y_coord == m_snake_tail.coord.y)
        return true;
    auto comp = [&](Tile &tile) -> bool {
        return tile.coord.x == x_coord && tile.coord.y == y_coord;
    };
    return std::ranges::any_of(m_snake_body.begin(), m_snake_body.end(), comp);
}
