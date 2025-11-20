/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#include "Decepticon.h"
#include <iostream>

Decepticon::Decepticon(
    const std::string& name,
    int level, int strength, int fuel, int ammo,
    const std::string& gunModel,
    Alliance* ally,
    bool hasDarkSpark
)
    : Transformer(name, level, strength, fuel, ammo, gunModel, ally),
      hasDarkSpark_(hasDarkSpark) {}

bool Decepticon::transform() {
    std::cout << getName() << " transforms to jet mode!" << std::endl;
    return true;
}

bool Decepticon::activateStealth() {
    std::cout << getName() << " activates stealth mode!" << std::endl;
    return true;
}

bool Decepticon::hasDarkSpark() const { return hasDarkSpark_; }
void Decepticon::setDarkSpark(bool has) { hasDarkSpark_ = has; }
