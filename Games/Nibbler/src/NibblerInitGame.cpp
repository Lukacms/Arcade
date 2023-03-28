/*
** EPITECH PROJECT, 2023
** src
** File description:
** NibblerInitGame
*/

#include <Nibbler/NibblerGame.hh>
#include <arcade/Opts.hh>
#include <exception>
#include <fstream>
#include <string>
#include <vector>

static std::vector<std::string> get_save_info(std::ifstream &save)
{
    std::vector<std::string> info_save{};
    std::string buff{};

    while (std::getline(save, buff))
        info_save.emplace_back(buff);
    // highest m_score
    // name of player
    if (info_save.size() != 2)
        throw arc::Opts{"save have a problem or was edited"};
    return info_save;
}

void NibblerGame::InitGame()
{
    std::ifstream save{"./.nibbler_save"};
    std::vector<std::string> info_save{};

    m_snake.reset_snake();
    m_score.current_score = 0;
    if (save.is_open()) {
        info_save = get_save_info(save);
        m_score
    }
}
