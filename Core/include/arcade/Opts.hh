/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** Opts
*/

#pragma once

#include <arcade/Core.hh>
#include <exception>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

// utils
constexpr std::string_view LIBS_PATHS{"./lib"};

// error messages
constexpr std::string_view OPTS_WRONG_LIB{"Lib given not a display"};
constexpr std::string_view CORE_NOLIBS{"No shared libraries found"};
constexpr std::string_view CORE_LIB_NOT_LOADING{
    "Libary given in argument not loading. Check the given path."};

namespace arc
{
    class Opts
    {
        public:
            Opts(std::string pstarting_display);
            Opts(Opts const &to_copy) = delete;
            Opts(Opts &&to_move) = delete;
            ~Opts() = default;
            Opts &operator=(Opts const &to_copy) = delete;

            // methods

            /**
             * load arguments in class Core
             *
             * handle error handling of library given in parameter
             * */
            arc::Core getOpts();
            void loadLibs();
            void loadStartingDisplay();

            // error class
            class OptsException : public std::exception
            {
                public:
                    OptsException(std::string perror_msg) : error_msg{std::move(perror_msg)} {}

                    OptsException(OptsException const &to_copy) = delete;
                    OptsException(OptsException &&to_move) = default;
                    ~OptsException() override = default;
                    OptsException &operator=(OptsException const &to_copy) = default;

                    [[nodiscard]] const char *what() const noexcept override;

                private:
                    std::string error_msg;
            };

        private:
            std::string starting_display{};
            arc::Core core{};

            bool checkDisplay(const std::vector<std::string> &displays);
    };
} // namespace arc
