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
    // Creating Alliances
    Alliance autobots("Autobots");
    Alliance decepticons("Decepticons");

    // Creating all sorts of objects
    Autobot optimus("Optimus Prime", 10, 100, 50, 20, "Ion Blaster", &autobots, true);
    Decepticon megatron("Megatron", 10, 110, 40, 25, "Fusion Cannon", &decepticons, true);
    Pretender ninja("Ninja", 8, 80, 30, 15, "Shuriken Launcher", &autobots, true);

    // getter tests
    std::cout << "Optimus name: " << optimus.getName() << std::endl;
    std::cout << "Optimus level: " << optimus.getLevel() << std::endl;
    std::cout << "Megatron fuel: " << megatron.getFuel() << std::endl;
    std::cout << "Ninja strength: " << ninja.getStrength() << std::endl;

    // setter test
    optimus.setLevel(11);
    optimus.setStrength(105);
    optimus.setFuel(55);
    std::cout << "Optimus new level: " << optimus.getLevel()
              << ", Optimus new strength: " << optimus.getStrength()
              << ", Optimus new fuel: " << optimus.getFuel() << std::endl;

    // Virtual methods tests
    optimus.move();
    optimus.fire();
    std::cout << "Optimus fuel after move: " << optimus.getFuel() << std::endl;
    std::cout << "Optimus gun ammo after fire: " << optimus.getGun().getAmmo() << std::endl;

    // Unique nethods tests
    optimus.transform();
    megatron.transform();
    ninja.transform();

    optimus.callForBackup();
    megatron.activateStealth();
    ninja.detachShell();

    //  Composition test
    std::cout << "Optimus gun model: " << optimus.getGun().getModel() << std::endl;
    std::cout << "Megatron gun ammo: " << megatron.getGun().getAmmo() << std::endl;

    // Modify gun via setter and verify
    optimus.getGun().setAmmo(30);
    std::cout << "Optimus gun ammo after set: " << optimus.getGun().getAmmo() << std::endl;

    // Association tests
    std::cout << "Optimus alliance: " << optimus.getAlliance()->getName() << std::endl;
    std::cout << "Megatron alliance: " << megatron.getAlliance()->getName() << std::endl;
    std::cout << "Ninja alliance: " << ninja.getAlliance()->getName() << std::endl;

    // test derived class specific getters/setters
    std::cout << "Optimus has Matrix: " << (optimus.hasMatrixOfLeadership() ? "yes" : "no") << std::endl;
    std::cout << "Megatron has Dark Spark: " << (megatron.hasDarkSpark() ? "yes" : "no") << std::endl;
    std::cout << "Ninja is human shell:" << (ninja.isHumanShell() ? "yes" : "no") << std::endl;

    // Modify and verify
    optimus.setMatrixOfLeadership(false);
    std::cout << "Optimus Matrix after set: " << (optimus.hasMatrixOfLeadership() ? "yes" : "no") << std::endl;

    return 0;
}
