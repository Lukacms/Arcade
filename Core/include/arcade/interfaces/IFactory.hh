/*
** EPITECH PROJECT, 2023
** interfaces
** File description:
** IFactory
*/

#pragma once

#include <arcade/interfaces/ISprite.hh>
#include <arcade/interfaces/IText.hh>
#include <memory>

namespace arc
{
    class IFactory
    {
        public:
            IFactory() = default;
            IFactory(IFactory const &to_copy) = default;
            IFactory(IFactory &&to_move) = delete;
            IFactory &operator=(IFactory const &to_copy) = default;
            IFactory &operator=(IFactory &&to_move) = delete;
            virtual ~IFactory();
            virtual std::unique_ptr<ISprite> CreateISprite() = 0;
            virtual std::unique_ptr<IText> CreateIText() = 0;
    };
} // namespace arc
