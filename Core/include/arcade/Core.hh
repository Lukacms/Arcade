/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Core
*/

#pragma once

#include <algorithm>
#include <arcade/interfaces/IDisplay.hh>
#include <arcade/interfaces/IGame.hh>
#include <exception>
#include <memory>
#include <string>
#include <vector>

const std::vector<std::string> DISPLAYS{"./lib/arcade_ncurses.so", "./lib/arcade_sdl.so",
                                        "./lib/arcade_sfml.so"};
const std::vector<std::string> GAMES{"./lib/arcade_nibbler.so", "./lib/arcade_snake.so"};

// exception messages
constexpr std::string_view WRONG_FILEPATH{"Filepath not correct."};
constexpr std::string_view DLOPEN_ERR{"Dlopen malfunction."};
constexpr std::string_view LIB_FORMAT_ERR{"Lib does not exists"};

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
            [[nodiscard]] std::vector<std::string> getSharedLibs() const;
            [[nodiscard]] std::vector<std::string> getSharedDisplays() const;
            [[nodiscard]] std::vector<std::string> getSharedGames() const;
            [[nodiscard]] std::string getActiveDisplay() const;
            [[nodiscard]] std::string getActiveGame() const;
            [[nodiscard]] std::reference_wrapper<arc::IDisplay> getIDisplay() const;
            [[nodiscard]] std::reference_wrapper<arc::IGame> getIGame() const;
            void addSharedLib(std::string filepath);

            // TODO make class methods (and implement them)
            // methods
            void isGameOrGraphic(const std::string &filepath);

            // error class
            class CoreException : public std::exception
            {
                public:
                    CoreException(std::string perror_msg) : error_msg{std::move(perror_msg)} {}

                    CoreException(CoreException const &to_copy) = delete;
                    CoreException(CoreException &&to_move) = delete;
                    ~CoreException() override = default;
                    CoreException &operator=(CoreException const &to_copy) = default;

                    [[nodiscard]] const char *what() const noexcept override;

                private:
                    std::string error_msg;
            };

        private:
            // go either like that
            std::vector<std::string> shared_libs{};
            // or that, idk the best way
            std::vector<std::string> shared_displays{};
            std::vector<std::string> shared_games{};
            // NOTE is it useful ?
            std::string active_display{};
            std::string active_game{};
            // not implemeted yet
            std::unique_ptr<arc::IGame> game{nullptr};
            std::unique_ptr<arc::IDisplay> display{nullptr};
    };
} // namespace arc
