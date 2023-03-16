/*
** EPITECH PROJECT, 2023
** include
** File description:
** ADisplay
*/

#pragma once

#include "core/include/arcade/interfaces/IDisplay.hh"
#include "core/include/arcade/interfaces/IWindow.hh"
#include <memory>

namespace arc
{
    class ADisplay : public IDisplay
    {
        protected:
            std::unique_ptr<arc::IWindow> m_window;
            bool m_is_game_switch{false};
            bool m_is_display_switch{false};

        public:
            ADisplay() = delete;
            ADisplay(ADisplay const &to_copy) = delete;
            ADisplay(ADisplay &&to_move) = delete;
            ADisplay &operator=(ADisplay const &to_copy) = delete;
            ADisplay &operator=(ADisplay const &&to_move) = delete;
            [[nodiscard]] arc::IWindow &GetWindow() final;
            [[nodiscard]] bool IsDisplaySwitch() final;
            [[nodiscard]] bool IsGameSwitch() final;
    };
} // namespace arc
