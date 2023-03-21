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
#include <utility>

constexpr char const *CORE_NOLIBS = "No shared libraries found";
constexpr char const *CORE_LIB_NOT_LOADING =
    "Libary given in argument not loading. Check the path.";

namespace arc
{
    class Opts
    {
        public:
            Opts() = default;
            Opts(Opts const &to_copy) = delete;
            Opts(Opts &&to_move) = delete;
            ~Opts() = delete;
            Opts &operator=(Opts const &to_copy) = delete;

            // methods

            /**
             * load arguments in class Core
             *
             * handle error handling of library given in parameter
             * */
            static arc::Core getOpts(const std::string &starting_lib);
            void loadLibs();
            void getStartingDisplay(const std::string &starting_lib);

            // error class
            class OptsException : public std::exception
            {
                public:
                    OptsException(std::string perror_msg) : error_msg{std::move(perror_msg)} {}

                    OptsException(OptsException const &to_copy) = delete;
                    OptsException(OptsException &&to_move) = delete;
                    ~OptsException() override = default;
                    OptsException &operator=(OptsException const &to_copy) = default;

                    [[nodiscard]] const char *what() const noexcept override;

                private:
                    std::string error_msg;
            };

        private:
            std::string starting_display{};
    };
} // namespace arc
