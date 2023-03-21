/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core
*/

#pragma once

#include <arcade/interfaces/IDisplay.hh>
#include <exception>
#include <memory>
#include <string>
#include <vector>

namespace arc
{
    class Core
    {
        public:
            Core() = default;
            Core(Core const &to_copy) = delete;
            Core(Core &&to_move) = default;
            ~Core() = default;
            Core &operator=(Core const &to_copy) = delete;
            Core &operator=(Core &&to_move) = default;

            // getter and setters
            const std::vector<std::string> getSharedLibs();
            const std::string getActiveDisplay();
            const std::string getActiveGame();
            const std::reference_wrapper<arc::IDisplay> getIDisplay();

            // TODO make class methods (and implement them)

            // error class
            class CoreException : public std::exception
            {
                public:
                    CoreException() = default;
                    CoreException(CoreException const &to_copy) = delete;
                    CoreException(CoreException &&to_move) = delete;
                    ~CoreException() override = default;
                    CoreException &operator=(CoreException const &to_copy) = default;

                    [[nodiscard]] const char *what() const noexcept override;
            };

        private:
            // go either like that
            std::vector<std::string> shared_libs{};
            // or that, idk the best way
            std::vector<std::string> shared_displays{};
            std::vector<std::string> shared_games{};
            // NOTE is it useful ?
            std::string active_display{};
            // not implemeted yet
            // std::unique_ptr<arc::IGame> active_game{nullptr};
            std::unique_ptr<arc::IDisplay> display{nullptr};
    };
} // namespace arc
