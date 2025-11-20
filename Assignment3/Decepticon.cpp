/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 4
 */

#include "Decepticon.h"
#include <iostream>

Decepticon::Decepticon()
    : Transformer("Decepticon", 1, 10, 10, 5, "Plasma Cannon", new Alliance("Decepticons")),
      hasDarkSpark_(false) {}

Decepticon::Decepticon(
    const std::string& name,
    int level, int strength, int fuel, int ammo,
    const std::string& gunModel,
    Alliance* ally,
    bool hasDarkSpark
)
    : Transformer(name, level, strength, fuel, ammo, gunModel, ally),
      hasDarkSpark_(hasDarkSpark) {}

bool Decepticon::transform()
{
    std::cout << "[Decepticon::transform] called" << std::endl;
    return true;
}

void Decepticon::specialAbility()
{
    std::cout << "[Decepticon::specialAbility] called" << std::endl;
}

bool Decepticon::activateStealth()
{
    std::cout << "[Decepticon::activateStealth] called" << std::endl;
    return true;
}

void Decepticon::corruptCore()
{
    std::cout << "[Decepticon::corruptCore] called" << std::endl;
}

bool Decepticon::hasDarkSpark() const
{
    return hasDarkSpark_;
}
void Decepticon::setDarkSpark(bool has)
{
    hasDarkSpark_ = has;
}

void Decepticon::print(std::ostream& os) const
{
    os << "[Decepticon] " << getName()
       << ", Level: " << getLevel()
       << ", Fuel: " << getFuel()
       << ", Has Dark Spark: " << (hasDarkSpark_ ? "yes" : "no");
}
