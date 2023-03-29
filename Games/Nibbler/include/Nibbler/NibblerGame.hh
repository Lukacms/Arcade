/*
** EPITECH PROJECT, 2023
** Nibbler
** File description:
** NibblerGame
*/

#pragma once

#include <Nibbler/Nibbler.hh>
#include <arcade/interfaces/IGame.hh>
#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IText.hh>
#include <chrono>
#include <memory>
#include <vector>

struct Score {
        int highscore;
        int current_score;
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

        void move_snake_analyse(const arc::Vector &snake_head_position, int x_add, int y_add,
                                Orient orient);
        void EventAnalisys(const arc::Event &event) final;
        void PlayGame() final; // TODO
        void ResetGame() final;
        void InitGame() final; // TODO
        void SetSprite(arc::IDisplay &display) final;
        void SetText(arc::IDisplay &display) final;

    private:
        Snake m_snake{};
        Score m_score{0, 0};
        std::chrono::steady_clock::time_point m_clock{};
        std::unique_ptr<arc::IText> m_text{};
        std::unique_ptr<arc::ISprite> m_sprite{};
        std::vector<std::string> m_map{};
};
