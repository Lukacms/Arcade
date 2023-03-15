/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** IEntity
*/

#pragma once

#include <string>
#include <arcade/Vector.hh>

namespace arc {

    class IEntity {
        public:
            IEntity() = delete;
            IEntity(IEntity &&) = delete;
            IEntity(const IEntity &);
            virtual ~IEntity() = 0;

            IEntity &operator=(const IEntity&);
            IEntity &operator=(IEntity &&) = delete;

            virtual void createEntity(std::string) = 0;
            [[nodiscard]] virtual IEntity &getEntity() = 0;
            virtual void destroyEntity() = 0;
            virtual void moveEntity(arc::Vector) = 0;
            virtual void setPosition(arc::Vector) = 0;
            virtual void drawEntity() = 0;
    };
}
