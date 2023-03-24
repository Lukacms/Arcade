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
#include <cstddef>
#include <exception>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

const std::vector<std::string> DISPLAYS{"./lib/arcade_ncurses.so", "./lib/arcade_sdl.so",
                                        "./lib/arcade_sfml.so"};
const std::vector<std::string> GAMES{"./lib/arcade_nibbler.so", "./lib/arcade_snake.so"};

const std::string_view LOAD_METHOD = "entryPoint";

// exception messages
constexpr std::string_view WRONG_FILEPATH{"Filepath not correct."};
constexpr std::string_view DLOPEN_ERR{"Dlopen malfunction."};
constexpr std::string_view LIB_FORMAT_ERR{"Lib does not exists"};
constexpr std::string_view LIB_LOADING_ERR{"Shared library can't be loaded."};
constexpr std::string_view LIB_OBJ_LOAD_ERR{"Does not have a method to load object."};

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
            [[nodiscard]] const std::vector<std::string> &getSharedDisplays() const;
            [[nodiscard]] const std::vector<std::string> &getSharedGames() const;
            [[nodiscard]] const std::string &getNextDisplay();
            [[nodiscard]] const std::string &getPrevDisplay();
            [[nodiscard]] const std::string &getNextGame();
            [[nodiscard]] const std::string &getPrevGame();
            [[nodiscard]] std::reference_wrapper<arc::IDisplay> getIDisplay() const;
            [[nodiscard]] std::reference_wrapper<arc::IGame> getIGame() const;

            // NOTE make class methods (and implement them)
            // methods to load a dynamic library
            void isGameOrGraphic(const std::string &filepath);
            void changeDisplay(const std::string &filepath);
            void changeGame(const std::string &filepath);

            // methods to manipulate them
            void handDisplay();
            void handEvents();

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
            std::vector<std::string> shared_displays{};
            std::vector<std::string> shared_games{};
            std::size_t display_ind{0};
            std::size_t game_ind{0};
            std::unique_ptr<arc::IGame> game{nullptr};
            std::unique_ptr<arc::IDisplay> display{nullptr};
    };
} // namespace arc
