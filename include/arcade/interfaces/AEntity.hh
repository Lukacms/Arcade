/*
** EPITECH PROJECT, 2023
** Arcade
** File description:
** AEntity
*/

#pragma once

#include <string>
#include <arcade/Geometry.hh>
#include <arcade/interfaces/IEntity.hh>

namespace arc {

    class AEntity : public IEntity {
        public:
            AEntity();
            AEntity(const AEntity&) = delete;
            ~AEntity() override;

            AEntity &operator=(const AEntity&);

            void moveEntity(arc::Vector vector) final;
            void setPosition(arc::Vector position) final;
            void setSize(arc::Vector size) final;
            void setRectangle(arc::Rect rectangle) final;
            IEntity &getEntity() final;


        protected:
            arc::Vector entityPosition{0, 0};
            arc::Vector entitySize{1, 1};
            arc::Rect entityRect{1, 1, 1, 1};
    };
}
