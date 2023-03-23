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
#include <memory>
#include <vector>

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
        bool m_exit{false};
};
