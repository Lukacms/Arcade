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
            virtual std::unique_ptr<ISprite> CreateISprite(const std::string &path) = 0;
            virtual std::unique_ptr<IText> CreateIText(const std::string &path) = 0;
            // créé la window
    };
} // namespace arc
