/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#include "Decepticon.h"

Decepticon::Decepticon()
    : Transformer("Decepticon", 1, 10, 10, 5, "Plasma", nullptr),
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

bool Decepticon::transform() { return true; }
bool Decepticon::specialAbility() { return true; }
bool Decepticon::activateStealth() { return true; }
void Decepticon::corruptCore() {}

bool Decepticon::hasDarkSpark() const { return hasDarkSpark_; }
void Decepticon::setDarkSpark(bool has) { hasDarkSpark_ = has; }
