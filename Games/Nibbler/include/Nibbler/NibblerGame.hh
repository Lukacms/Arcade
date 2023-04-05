/*
** EPITECH PROJECT, 2023
** Nibbler
** File description:
** NibblerGame
*/
#pragma once
#include "Nibbler/ClockNibbler.hh"
#include <Nibbler/Nibbler.hh>
#include <arcade/interfaces/IGame.hh>
#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IText.hh>
#include <arcade/interfaces/IWindow.hh>
#include <chrono>
#include <memory>
#include <vector>

constexpr arc::Color const WALL_COLOR{255, 69, 0};
constexpr arc::Color const TEXT_COLOR{255, 255, 255};
constexpr int const NUMBER_APPLE{5};
constexpr arc::Vector GAME_OVER_POSITION{8, 10};

enum class GameState {
    Play,
    Pause,
    GameOver,
};

struct Score {
        int highscore;
        int current_score;
};

class NibblerGame : public arc::IGame
{
    public:
        NibblerGame() = default;
        NibblerGame(NibblerGame const &to_copy) = delete;
        NibblerGame(NibblerGame &&to_move) = default;
        ~NibblerGame() override = default;
        NibblerGame &operator=(NibblerGame const &to_copy) = delete;
        NibblerGame &operator=(NibblerGame &&to_move) = default;

        void ResetGame() final;
        void EventAnalisys(const arc::Event &event) final;
        void SetSprite(arc::IDisplay &display) final;
        void SetText(arc::IDisplay &display) final;
        void move_snake_analyse(const arc::Vector &snake_head_position, int x_add, int y_add,
                                Orient orient);
        void PlayGame() final;
        void InitGame() final;
        void DisplayGame(arc::IWindow &window) final;

    private:
        void check_if_corner_n();
        void check_if_corner_s();
        void check_if_corner_e();
        void check_if_corner_w();
        void check_colision();
        void move_snake();
        void init_level();
        void get_highscore();
        std::vector<Tile> get_file(const std::string &filepath, int fruit_index);

        bool m_wait_restart{false};
        int m_apple_number_needed{NUMBER_APPLE};
        int m_level_index{0};
        Score m_score{0, 0};
        std::unique_ptr<arc::IText> m_text{};
        std::unique_ptr<arc::ISprite> m_sprite{};
        NibblerClock m_timer{};
        Snake m_snake{};
        GameState m_state{GameState::Play};
        std::vector<Tile> m_map_tile{};
        std::vector<Tile> m_texts{};
        std::vector<Tile> m_fruits{};
        std::vector<std::vector<Tile>> m_fruits_level{};
        std::vector<std::vector<Tile>> m_level{};
};
