/*
** EPITECH PROJECT, 2023
** Nibbler
** File description:
** NibblerGame
*/

#pragma once

#include "arcade/interfaces/ISprite.hh"
#include "arcade/interfaces/IText.hh"
#include <arcade/interfaces/IGame.hh>
#include <memory>
#include <vector>

class NibblerGame : arc::IGame
{
    public:
        NibblerGame() = default;
        NibblerGame(NibblerGame const &to_copy) = delete;
        NibblerGame(NibblerGame &&to_move) = default;
        ~NibblerGame() override = default;
        NibblerGame &operator=(NibblerGame const &to_copy) = delete;
        NibblerGame &operator=(NibblerGame &&to_move) = default;
        void EventAnalisys(const arc::Event &event) final;

    private:
        std::vector<std::unique_ptr<arc::ISprite>> m_map;
        std::vector<std::unique_ptr<arc::ISprite>> m_snake;
        std::vector<std::unique_ptr<arc::IText>> m_text;
};
