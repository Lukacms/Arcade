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
            [[nodiscard]] std::reference_wrapper<arc::IWindow> GetWindow() final;
            ADisplay() = default;
            ADisplay(ADisplay const &to_copy) = delete;
            ADisplay(ADisplay &&to_move) = default;
            ~ADisplay() override = default;

            ADisplay &operator=(ADisplay const &to_copy) = delete;
            ADisplay &operator=(ADisplay &&to_move) = default;
    };
} // namespace arc
