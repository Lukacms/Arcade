/*
** EPITECH PROJECT, 2023
** src
** File description:
** Error
*/

#include <Nibbler/Error.hh>

const char *Error::what() const noexcept
{
    return m_error_msg.c_str();
}

Error::Error(const std::string &msg) : m_error_msg(msg) {}
