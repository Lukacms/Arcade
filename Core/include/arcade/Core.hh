/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core
*/

#pragma once

#include "arcade/interfaces/IDisplay.hh"
#include <exception>
#include <functional>
#include <memory>
#include <string>
#include <vector>

constexpr char const *CORE_NOLIBS = "No shared libraries found";
constexpr char const *CORE_LIB_NOT_LOADING =
    "Libary given in argument not loading. Check the path.";

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

            // getter and setters
            const std::vector<std::string> getSharedLibs();
            const std::string getActiveDisplay();
            const std::string getActiveGame();
            const std::reference_wrapper<arc::IDisplay> getIDisplay();

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
            std::vector<std::string> shared_libs{};
            std::string active_display{};
            std::string active_game{};
            std::unique_ptr<arc::IDisplay> display;
    };
} // namespace arc
