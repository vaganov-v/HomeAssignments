/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 4
 */

#ifndef ALLIANCE_H
#define ALLIANCE_H

#include <string>

class Alliance
{
public:
    Alliance();
    explicit Alliance(const std::string& name);
    const std::string& getName() const;

private:
    std::string name_;
};

#endif
