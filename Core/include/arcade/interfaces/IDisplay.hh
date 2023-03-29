/*
** EPITECH PROJECT, 2023
** display
** File description:
** display
*/

#pragma once

#include "arcade/interfaces/ISprite.hh"
#include "arcade/interfaces/IText.hh"
#include <arcade/enum/EventEnum.hh>
#include <arcade/interfaces/IWindow.hh>
#include <functional>
#include <memory>
#include <string>

namespace arc
{
    class IDisplay
    {
        public:
            virtual ~IDisplay() = default;
            IDisplay() = default;
            IDisplay(IDisplay const &to_copy) = default;
            IDisplay(IDisplay &&to_move) = default;
            IDisplay &operator=(IDisplay const &to_copy) = default;
            IDisplay &operator=(IDisplay &&to_move) = default;
            virtual std::unique_ptr<arc::ISprite> createSprite() = 0; // factory
            virtual std::unique_ptr<arc::IText> createText() = 0;     // factory
            [[nodiscard]] virtual std::reference_wrapper<arc::IWindow>
            GetWindow() = 0;                                     // create window
            [[nodiscard]] virtual arc::Event GetEvent() = 0;     // window
            [[nodiscard]] virtual std::string GetUserName() = 0; // dans les jeux
    };
} // namespace arc
