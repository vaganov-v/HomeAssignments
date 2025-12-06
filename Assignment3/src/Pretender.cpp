/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#include "Pretender.h"

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

bool Pretender::transform() { return true; }
bool Pretender::specialAbility() { return true; }
bool Pretender::detachShell() { return true; }
void Pretender::mimicAlliance() {}

bool Pretender::isHumanShell() const { return isHumanShell_; }
void Pretender::setHumanShell(bool is) { isHumanShell_ = is; }
