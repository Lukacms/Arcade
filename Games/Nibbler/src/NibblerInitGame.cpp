/*
** EPITECH PROJECT, 2023 ** src
** File description:
** NibblerInitGame
*/

#include "Nibbler/Nibbler.hh"
#include <Nibbler/NibblerGame.hh>
#include <arcade/Opts.hh>
#include <arcade/RuntimeExecption.hh>
#include <exception>
#include <fstream>
#include <memory>
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
        throw arc::RuntimeExecption{"ERROR"};
    return info_save;
}

static bool check_file(const std::vector<std::string> &parsed_file)
{
    int apple_counter{0};

    if (parsed_file.size() < MAP_HEIGHT)
        return false;
    if (parsed_file[0] != "xxxxxxxxxxxxxxxxxxxx" ||
        parsed_file[MAP_HEIGHT - 1] != "xxxxxxxxxxxxxxxxxxxx")
        return false;
    for (std::string line : parsed_file) {
        if (line.size() < MAP_WIDTH)
            return false;
        if (line[0] != 'x' || line[MAP_WIDTH - 1] != 'x')
            return false;
        for (char c_map : line) {
            if (c_map != '\n' && c_map != 'x' && c_map != ' ')
                return false;
            if (c_map == 'p')
                apple_counter++;
        }
    }
    return apple_counter != 0;
}

std::vector<Tile> NibblerGame::get_file(const std::string &filepath, int fruit_index)
{
    std::vector<Tile> parsed_file{};
    std::ifstream filestream{filepath};
    std::string buff{};
    int count{0};

    if (!filestream.is_open())
        throw arc::RuntimeExecption{"ERROR"};
    while (std::getline(filestream, buff)) {
        for (int i = 0; i < buff.size(); i++) {
            if (buff[i] == 'x')
                parsed_file.emplace_back(Tile{i, count});
            if (buff[i] == 'p')
                m_fruits_level[fruit_index].emplace_back(Tile{i, count});
        }
        count++;
    }
    return parsed_file;
}

void NibblerGame::init_level()
{
    if (m_fruits_level.empty()) {
        m_fruits_level.emplace_back();
        m_fruits_level.emplace_back();
        m_fruits_level.emplace_back();
    }
    if (m_level.empty()) {
        m_level.emplace_back(get_file("./assets/map/map1", 0));
        m_level.emplace_back(get_file("./assets/map/map2", 1));
        m_level.emplace_back(get_file("./assets/map/map3", 2));
    }
}

void NibblerGame::get_highscore()
{
    std::ifstream hiscore_stream{"./.nibbler_save"};
    std::string hiscore;

    if (!hiscore_stream.is_open()) {
        m_score.highscore = 0;
        return;
    }
    hiscore_stream >> hiscore;
    for (auto character : hiscore) {
        if (character < '0' || character > '9') {
            m_score.highscore = 0;
            return;
        }
    }
    m_score.highscore = std::stoi(hiscore);
    hiscore_stream.close();
}

void NibblerGame::InitGame()
{
    Tile text_tile;

    text_tile.coord = SCORE_POSITION;
    this->m_texts.push_back(text_tile);
    text_tile.coord = HIGHSCORE_POSITION;
    this->m_texts.push_back(text_tile);

    m_snake.reset_snake();
    m_score.current_score = 0;
    get_highscore();
    init_level();
    m_map_tile = m_level[0];
    m_fruits = m_fruits_level[0];
}
