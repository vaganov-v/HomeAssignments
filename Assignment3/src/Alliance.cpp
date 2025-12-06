/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 4
 */

#include "Alliance.h"

Alliance::Alliance() : name_("Unknown") {}

Alliance::Alliance(const std::string& name)
    : name_(name) {}

const std::string& Alliance::getName() const
{
    return name_;
}

