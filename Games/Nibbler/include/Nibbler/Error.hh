/*
** EPITECH PROJECT, 2023
** Nibbler
** File description:
** Error
*/

#pragma once

#include <exception>
#include <string>

class Error final : public std::exception
{
    private:
        const std::string m_error_msg;

    public:
        Error() = delete;
        Error(Error const &to_copy) = delete;
        Error(Error &&to_move) = delete;
        ~Error() final = default;
        Error &operator=(Error const &to_copy) = delete;
        Error &operator=(Error &&to_move) = delete;

        Error(const std::string &msg);
        [[nodiscard]] const char *what() const noexcept override;
};

