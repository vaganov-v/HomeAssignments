/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 4
 */

#include "Transformer.h"
#include <iostream>

Transformer::Transformer()
    : name_("Unknown"), level_(1), strength_(10), fuel_(10),
      gun_("Basic", 5), ally_(new Alliance()) {}

Transformer::Transformer(
    const std::string& name,
    int level, int strength, int fuel, int ammo,
    const std::string& gunModel,
    Alliance* ally
)
    : name_(name), level_(level), strength_(strength), fuel_(fuel),
      gun_(gunModel, ammo), ally_(ally) {}

Transformer::~Transformer() {}

const std::string& Transformer::getName() const
{
    return name_;
}
int Transformer::getLevel() const
{
    return level_;
}
int Transformer::getStrength() const
{
    return strength_;
}
int Transformer::getFuel() const
{
    return fuel_;
}
Gun& Transformer::getGun()
{
    return gun_;
}
Alliance* Transformer::getAlliance() const
{
    return ally_;
}

void Transformer::setLevel(int level)
{
    level_ = level;
}
void Transformer::setStrength(int strength)
{
    strength_ = strength;
}
void Transformer::setFuel(int fuel)
{
    fuel_ = fuel;
}

bool Transformer::move()
{
    std::cout << "[" << name_ << "::move] called" << std::endl;
    if (fuel_ > 0)
    {
        --fuel_;
        return true;
    }
    return false;
}

bool Transformer::fire()
{
    std::cout << "[" << name_ << "::fire[ called" << std::endl;
    if (gun_.getAmmo() > 0)
    {
        gun_.setAmmo(gun_.getAmmo() - 1);
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Transformer& t) {
    t.print(os);
    return os;
}
