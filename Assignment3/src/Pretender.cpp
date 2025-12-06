/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 4
 */

#include "Pretender.h"
#include <iostream>

Pretender::Pretender()
    : Transformer("Pretender", 1, 10, 10, 5, "Shell", nullptr),
      isHumanShell_(true) {}

Pretender::Pretender(
    const std::string& name,
    int level, int strength, int fuel, int ammo,
    const std::string& gunModel,
    Alliance* ally,
    bool isHuman
)
    : Transformer(name, level, strength, fuel, ammo, gunModel, ally),
      isHumanShell_(isHuman) {}

bool Pretender::transform()
{
    std::cout << "[Pretender::transform] called" << std::endl;
    return true;
}

bool Pretender::specialAbility()
{
    std::cout << "[Pretender::specialAbility] called" << std::endl;
    return true;
}

bool Pretender::detachShell()
{
    std::cout << "[Pretender::detachShell] called" << std::endl;
    return true;
}

void Pretender::mimicAlliance()
{
    std::cout << "[Pretender::mimicAlliance] called" << std::endl;
}

bool Pretender::isHumanShell() const
{
    return isHumanShell_;
}
void Pretender::setHumanShell(bool is)
{
    isHumanShell_ = is;
}

void Pretender::print(std::ostream& os) const
{
    os << "[Pretender] " << name_
       << ", Level: " << level_
       << ", Fuel: " << fuel_
       << ", Human Shell: " << (isHumanShell_ ? "yes" : "no");
}
