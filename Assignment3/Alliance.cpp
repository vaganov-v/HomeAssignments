/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#include "Alliance.h"

Alliance::Alliance(const std::string& name)
    : name_(name) {}

const std::string& Alliance::getName() const { return name_; }
