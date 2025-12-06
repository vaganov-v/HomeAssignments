/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 4
 */

#include "Autobot.h"
#include <iostream>

Autobot::Autobot()
    : Transformer("Autobot", 1, 10, 10, 5, "Standard", nullptr),
      hasMatrixOfLeadership_(false) {}

Autobot::Autobot(
    const std::string& name,
    int level, int strength, int fuel, int ammo,
    const std::string& gunModel,
    Alliance* ally,
    bool hasMatrix
)
    : Transformer(name, level, strength, fuel, ammo, gunModel, ally),
      hasMatrixOfLeadership_(hasMatrix) {}

bool Autobot::transform()
{
    std::cout << "[Autobot::transform] called" << std::endl;
    return true;
}

bool Autobot::specialAbility()
{
    std::cout << "[Autobot::specialAbility] called" << std::endl;
    return true;
}

bool Autobot::callForBackup()
{
    std::cout << "[Autobot::callForBackup] called" << std::endl;
    return true;
}

void Autobot::recharge()
{
    std::cout << "[Autobot::recharge] called" << std::endl;
}

bool Autobot::hasMatrixOfLeadership() const
{
    return hasMatrixOfLeadership_;
}
void Autobot::setMatrixOfLeadership(bool has)
{
    hasMatrixOfLeadership_ = has;
}

void Autobot::print(std::ostream& os) const
{
    os << "[Autobot] " << name_
       << ", Level: " << level_
       << ", Fuel: " << fuel_
       << ", Has Matrix: " << (hasMatrixOfLeadership_ ? "yes" : "no");
}
