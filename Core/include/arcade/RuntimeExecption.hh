/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** RuntimeExecption
*/

#include <exception>
#include <string>

#pragma once

namespace arc
{
    class RuntimeExecption : public std::exception
    {
        private:
            const std::string m_error_msg;

        public:
            RuntimeExecption() = delete;
            RuntimeExecption(const std::string &msg);
            RuntimeExecption(RuntimeExecption &&to_move) = delete;
            RuntimeExecption(RuntimeExecption const &to_copy) = delete;
            ~RuntimeExecption() override = default;
            RuntimeExecption &operator=(RuntimeExecption const &to_copy) = delete;
            RuntimeExecption &operator=(RuntimeExecption &&to_move) = delete;

            [[nodiscard]] const char *what() const noexcept override;
    };
} // namespace arc
