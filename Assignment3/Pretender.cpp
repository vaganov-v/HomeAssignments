/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#include "Pretender.h"
#include <iostream>

Pretender::Pretender(
    const std::string& name,
    int level, int strength, int fuel, int ammo,
    const std::string& gunModel,
    Alliance* ally,
    bool isHumanShell
)
    : Transformer(name, level, strength, fuel, ammo, gunModel, ally),
      isHumanShell_(isHumanShell) {}

bool Pretender::transform() {
    std::cout << getName() << " transforms and reveals true form!" << std::endl;
    return true;
}

bool Pretender::detachShell() {
    std::cout << getName() << " detaches pretender shell!" << std::endl;
    return true;
}

bool Pretender::isHumanShell() const { return isHumanShell_; }
void Pretender::setHumanShell(bool is) { isHumanShell_ = is; }
