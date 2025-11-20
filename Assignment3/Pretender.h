/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 4
 */

#ifndef PRETENDER_H
#define PRETENDER_H

#include "Transformer.h"

class Pretender : public Transformer
{
public:
    Pretender();
    Pretender(
        const std::string& name,
        int level,
        int strength,
        int fuel,
        int ammo,
        const std::string& gunModel,
        Alliance* ally,
        bool isHumanShell
    );

    bool transform() override;
    void specialAbility() override;
    bool detachShell();
    void mimicAlliance();

    bool isHumanShell() const;
    void setHumanShell(bool is);

    void print(std::ostream& os) const override;

private:
    bool isHumanShell_;
};

#endif
