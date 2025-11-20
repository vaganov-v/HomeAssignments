/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#ifndef PRETENDER_H
#define PRETENDER_H

#include "Transformer.h"

class Pretender : public Transformer {
public:
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
    bool detachShell();

    bool isHumanShell() const;
    void setHumanShell(bool is);

private:
    bool isHumanShell_;
};

#endif
