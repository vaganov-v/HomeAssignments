/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Home assignment 1
 */

#include "hello.h"
#include <iostream>
#include <string>

int main()
{
    myproject::sayHello();

    std::string input;
    while (std::getline(std::cin, input))
    {
        if (input.empty())
        {
            break;
        }
        myproject::sayHello(input);
    }

    return 0;
}
