/*
** EPITECH PROJECT, 2023
** core
** File description:
** RuntimeException
*/

#include <arcade/RuntimeExecption.hh>

const char *arc::RuntimeExecption::what() const noexcept
{
    return m_error_msg.c_str();
}

arc::RuntimeExecption::RuntimeExecption(const std::string &msg) : m_error_msg(msg) {}
