/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#include "Autobot.h"
#include "Decepticon.h"
#include "Pretender.h"
#include "Alliance.h"
#include <iostream>

int main() {
    Alliance autobots("Autobots");
    Alliance decepticons("Decepticons");

    Autobot optimus("Optimus Prime", 10, 100, 50, 20, "Ion Blaster", &autobots, true);
    Decepticon megatron("Megatron", 10, 110, 40, 25, "Fusion Cannon", &decepticons, true);
    Pretender ninja("Ninja", 8, 80, 30, 15, "Shuriken Launcher", &autobots, true);

    optimus.transform();
    megatron.transform();
    ninja.transform();

    optimus.callForBackup();
    megatron.activateStealth();
    ninja.detachShell();

    std::cout << "Optimus fuel: " << optimus.getFuel() << std::endl;
    optimus.move();
    std::cout << "After move: " << optimus.getFuel() << std::endl;

    return 0;
}
