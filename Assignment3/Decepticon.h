/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 4
 */

#ifndef DECEPTICON_H
#define DECEPTICON_H

#include "Transformer.h"

class Decepticon : public Transformer
{
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
    void specialAbility() override;
    bool activateStealth();
    void corruptCore();

    bool hasDarkSpark() const;
    void setDarkSpark(bool has);

    void print(std::ostream& os) onst override;

private:
    bool hasDarkSpark_;
};

#endif
