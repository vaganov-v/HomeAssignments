/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#ifndef ALLIANCE_H
#define ALLIANCE_H

#include <string>

class Alliance {
public:
    explicit Alliance(const std::string& name);
    const std::string& getName() const;

private:
    std::string name_;
};

#endif
