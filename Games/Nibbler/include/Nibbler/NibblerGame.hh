/*
** EPITECH PROJECT, 2023
** Nibbler
** File description:
** NibblerGame
*/

#pragma once

#include <arcade/interfaces/IGame.hh>
#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IText.hh>
#include <memory>
#include <vector>

enum class Orient { N, E, S, W, NONE };

struct Tile {
        int x_coord{};
        int y_coord{};
        Orient orientation{};
};

class Snake
{
    public:
        Snake() = default;
        Snake(Snake const &to_copy) = default;
        Snake(Snake &&to_move) = default;
        ~Snake() = default;
        Snake &operator=(Snake const &to_copy) = default;
        Snake &operator=(Snake &&to_move) = default;
        void move_snake(int x_coord, int y_coord);

    private:
        Tile m_head_snake{};
        std::vector<Tile> m_snake_body{};
        Tile m_snake_tail{};
};

class NibblerGame : arc::IGame
{
    public:
        NibblerGame();
        NibblerGame(NibblerGame const &to_copy) = delete;
        NibblerGame(NibblerGame &&to_move) = default;
        ~NibblerGame() override = default;
        NibblerGame &operator=(NibblerGame const &to_copy) = delete;
        NibblerGame &operator=(NibblerGame &&to_move) = default;
        void EventAnalisys(const arc::Event &event) final;
        void PlayGame() final;
        void SaveGame() final;
        void ResetGame() final;
        void LoadGame() final;
        void IsExit() final;
        void InitGame() final;

    private:
        Snake m_snake{};
        std::unique_ptr<arc::IText> m_text{};
        std::unique_ptr<arc::ISprite> m_sprite{};
        std::vector<std::string> m_map{};
};
