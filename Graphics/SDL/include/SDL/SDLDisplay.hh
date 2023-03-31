/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLDisplay
*/

#pragma once

#include <arcade/enum/EventEnum.hh>
#include <arcade/interfaces/IDisplay.hh>
#include <memory>
#include <arcade/interfaces/ADisplay.hh>

namespace arc
{

    class SDLDisplay : public ADisplay {
        public:
            SDLDisplay();
            SDLDisplay(SDLDisplay const &to_copy) = delete;
            SDLDisplay(SDLDisplay &&to_move) = delete;
            SDLDisplay &operator=(SDLDisplay const &to_copy) = delete;
            SDLDisplay &operator=(SDLDisplay const &&to_move) = delete;
            ~SDLDisplay() override = default;
            std::unique_ptr<arc::ISprite> createSprite() final;
            std::unique_ptr<arc::IText> createText() final;

            [[nodiscard]] arc::Event GetEvent() final;
    };

} // namespace arc