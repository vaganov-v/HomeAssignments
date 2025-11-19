/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 2b
 */

#include "rpn_calculator.h"
#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::getline(std::cin, input);

    double result;
    if (rpn::evaluate(input, result)) {
        std::cout << result << std::endl;
        return 0;
    } else {
        std::cerr << "Error: invalid RPN expression" << std::endl;
        return 1;
    }
}
