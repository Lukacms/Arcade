/*
** EPITECH PROJECT, 2023
** interfaces
** File description:
** IFactory
*/

#pragma once

#include <arcade/interfaces/IEntity.hh>
#include <memory>

namespace arc
{
    class IFactory
    {
        public:
            virtual ~IFactory();
            virtual std::unique_ptr<IEntity> CreateIEntity(const std::string &type) = 0;
            virtual std::unique_ptr<IEntity> ResetEntity(const std::string &type) = 0;
    };
} // namespace arc
