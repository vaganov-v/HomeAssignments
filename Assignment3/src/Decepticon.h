/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"

class Decepticon : public Transformer {
public:
    Decepticon();
    Decepticon(
        const std::string& name,
        int level,
        int strength,
        int fuel,
        int ammo,
        const std::string& gunModel,
        Alliance* ally,
        bool hasDarkSpark
    );

    bool transform() override;
    bool specialAbility() override;
    bool activateStealth();
    void corruptCore();

    bool hasDarkSpark() const;
    void setDarkSpark(bool has);

private:
    bool hasDarkSpark_;
};

#endif
