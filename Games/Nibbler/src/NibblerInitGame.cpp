/*
** EPITECH PROJECT, 2023 ** src
** File description:
** NibblerInitGame
*/

#include "Nibbler/Nibbler.hh"
#include <Nibbler/Error.hh>
#include <Nibbler/NibblerGame.hh>
#include <arcade/Opts.hh>
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
        throw Error{"save have a problem or was edited"};
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
        throw Error{"Cant find: " + filepath};
    while (std::getline(filestream, buff)) {
        for (int i = 0; i < buff.size(); i++) {
            if (buff[i] == 'x')
                parsed_file.emplace_back(Tile{i, count});
            if (buff[i] == 'p')
                m_fruits_level[fruit_index].emplace_back(Tile{i, count});
        }
        count++;
    }

    //    if (!check_file(parsed_file))
    //        throw Error{"file: " + filepath + " is badly written"};
    return parsed_file;
}

void NibblerGame::init_level()
{
    m_fruits_level.emplace_back();
    m_fruits_level.emplace_back();
    m_fruits_level.emplace_back();
    m_level.emplace_back(get_file("./assets/map/map1", 0));
    m_level.emplace_back(get_file("./assets/map/map2", 1));
    m_level.emplace_back(get_file("./assets/map/map3", 2));
}

void NibblerGame::InitGame()
{
    std::ifstream save{"./.nibbler_save"};
    std::vector<std::string> info_save{};

    m_snake.reset_snake();
    m_score.current_score = 0;
    if (save.is_open()) {
        info_save = get_save_info(save);
        m_score.highscore = std::atoi(info_save[0].c_str());
        if (m_score.highscore < 0)
            throw Error{"score shouldn't be under 0"};
    }
    init_level();
    m_map_tile = m_level[0];
    m_fruits = m_fruits_level[0];
}
