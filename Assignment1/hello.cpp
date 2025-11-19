/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Home assignment 1
 */

#include "hello.h"
#include <iostream>

namespace myproject
{

void sayHello()
{
    std::cout << "Hello, world!" << std::endl;
}

void sayHello(const std::string& name)
{
    std::cout << "Hello, " << name << "!" << std::endl;
}

}
