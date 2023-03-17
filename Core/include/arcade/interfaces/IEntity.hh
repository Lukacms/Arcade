/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IEntity
*/

#pragma once

#include "arcade/interfaces/IWindow.hh"
#include <string>
#include <arcade/Geometry.hh>

namespace arc {

    class IEntity {
        public:
            IEntity() = delete;
            IEntity(IEntity &&) = delete;
            IEntity(const IEntity &);
            virtual ~IEntity() = 0;

            IEntity &operator=(const IEntity&);
            IEntity &operator=(IEntity &&) = delete;

            virtual void createEntity(std::string str) = 0;
            virtual void createEntity(IEntity &) = 0;
            [[nodiscard]] virtual IEntity &getEntity() = 0;
            virtual void destroyEntity() = 0;
            virtual void moveEntity(arc::Vector vector) = 0;
            virtual void setPosition(arc::Vector vector) = 0;
            virtual void setSize(arc::Vector vector) = 0;
            virtual void setRectangle(arc::Rect rectangle);
            virtual void drawEntity(IWindow &window) = 0;
    };
}
