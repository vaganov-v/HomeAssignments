/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#include "Autobot.h"
#include <iostream>

Autobot::Autobot(
    const std::string& name,
    int level, int strength, int fuel, int ammo,
    const std::string& gunModel,
    Alliance* ally,
    bool hasMatrixOfLeadership
)
    : Transformer(name, level, strength, fuel, ammo, gunModel, ally),
      hasMatrixOfLeadership_(hasMatrixOfLeadership) {}

bool Autobot::transform() {
    std::cout << getName() << " transforms to truck mode!" << std::endl;
    return true;
}

bool Autobot::callForBackup() {
    std::cout << getName() << " calls for Autobot backup!" << std::endl;
    return true;
}

bool Autobot::hasMatrixOfLeadership() const { return hasMatrixOfLeadership_; }
void Autobot::setMatrixOfLeadership(bool has) { hasMatrixOfLeadership_ = has; }
