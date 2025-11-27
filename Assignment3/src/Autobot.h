/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#ifndef AUTOBOT_H
#define AUTOBOT_H

#include "Transformer.h"

class Autobot : public Transformer {
public:
    Autobot();
    Autobot(
        const std::string& name,
        int level,
        int strength,
        int fuel,
        int ammo,
        const std::string& gunModel,
        Alliance* ally,
        bool hasMatrix
    );

    bool transform() override;
    bool specialAbility() override;
    bool callForBackup();
    void recharge();

    bool hasMatrixOfLeadership() const;
    void setMatrixOfLeadership(bool has);

private:
    bool hasMatrixOfLeadership_;
};

#endif
