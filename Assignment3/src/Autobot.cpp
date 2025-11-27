/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#include "Autobot.h"

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

bool Autobot::transform() { return true; }
bool Autobot::specialAbility() { return true; }
bool Autobot::callForBackup() { return true; }
void Autobot::recharge() {}

bool Autobot::hasMatrixOfLeadership() const { return hasMatrixOfLeadership_; }
void Autobot::setMatrixOfLeadership(bool has) { hasMatrixOfLeadership_ = has; }
