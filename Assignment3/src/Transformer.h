/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include "Gun.h"
#include "Alliance.h"
#include <string>

class Transformer {
public:
    Transformer();
    Transformer(
        const std::string& name,
        int level,
        int strength,
        int fuel,
        int ammo,
        const std::string& gunModel,
        Alliance* ally
    );
    virtual ~Transformer();

    const std::string& getName() const;
    int getLevel() const;
    int getStrength() const;
    int getFuel() const;
    Gun& getGun();
    const Gun& getGun() const;
    Alliance* getAlliance() const;

    void setLevel(int level);
    void setStrength(int strength);
    void setFuel(int fuel);

    virtual bool move();
    virtual bool fire();
    virtual bool transform() = 0;
    virtual bool specialAbility() = 0;

protected:
    std::string name_;
    int level_;
    int strength_;
    int fuel_;
    Gun gun_;
    Alliance* ally_;
};

#endif
