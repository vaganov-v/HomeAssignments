/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 3
 */

#ifndef GUN_H
#define GUN_H

#include <string>

class Gun {
public:
    Gun();
    Gun(const std::string& model, int ammo);
    ~Gun();

    const std::string& getModel() const;
    int getAmmo() const;
    void setAmmo(int ammo);

private:
    std::string model_;
    int ammo_;
};

#endif
