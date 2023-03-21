/*
** EPITECH PROJECT, 2023
** include
** File description:
** ADisplay
*/

#pragma once

#include <arcade/interfaces/IDisplay.hh>
#include <arcade/interfaces/IWindow.hh>
#include <functional>
#include <memory>

namespace arc
{
    class ADisplay : public arc::IDisplay
    {
        protected:
            std::unique_ptr<arc::IWindow> m_window;

        public:
            ADisplay() = delete;
            ADisplay(ADisplay const &to_copy) = delete;
            ADisplay(ADisplay &&to_move) = delete;
            ADisplay &operator=(ADisplay const &to_copy) = delete;
            ADisplay &operator=(ADisplay const &&to_move) = delete;
            [[nodiscard]] std::reference_wrapper<arc::IWindow> GetWindow() final;
    };
} // namespace arc
