/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** SDLDisplay
*/

#pragma once

#include <arcade/enum/EventEnum.hh>
#include <arcade/interfaces/ADisplay.hh>

namespace arc {

    class SDLDisplay : public ADisplay {
        public:
            SDLDisplay();
            SDLDisplay(SDLDisplay const &to_copy) = delete;
            SDLDisplay(SDLDisplay &&to_move) = delete;
            SDLDisplay &operator=(SDLDisplay const &to_copy) = delete;
            SDLDisplay &operator=(SDLDisplay const &&to_move) = delete;
            ~SDLDisplay() override = default;

            [[nodiscard]] arc::Event GetEvent() final;
    };

}