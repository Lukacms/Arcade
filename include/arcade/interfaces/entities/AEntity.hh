/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AEntity
*/

#pragma once

#include <string>
#include <arcade/Vector.hh>
#include <arcade/interfaces/entities/IEntity.hh>

namespace arc {

    class AEntity : public IEntity {
        public:
            AEntity() = delete;
            AEntity(const AEntity&) = delete;
            ~AEntity() override;

            AEntity &operator=(const AEntity&);

            void moveEntity(arc::Vector vector) override;
            void setPosition(arc::Vector vector) override;
            IEntity &getEntity() override;


        private:
            arc::Vector entityPosition{0, 0};
    };
}
