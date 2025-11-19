/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 2b
 */

#include "rpn_calculator.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

namespace rpn {

bool evaluate(const std::string& expression, double& result)
{
    const int MAX_STACK_SIZE = 1000;
    double* stack = new double[MAX_STACK_SIZE];
    int top = -1; // top of the stacl

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (top < 1) {
                delete[] stack;
                return false; // not enough operands
            }
            double b = stack[top--];
            double a = stack[top--];
            double res = 0.0;
            if (token == "+") res = a + b;
            else if (token == "-") res = a - b;
            else if (token == "*") res = a * b;
            else if (token == "/") {
                if (b == 0) {
                    delete[] stack;
                    return false; // dividing by zero
                }
                res = a / b;
            }
            stack[++top] = res;
        } else {
            // trying to convert a number
            try {
                size_t pos;
                double num = std::stod(token, &pos);
                if (pos != token.length()) {
                    delete[] stack;
                    return false; // wrong content in number
                }
                if (top + 1 >= MAX_STACK_SIZE) {
                    delete[] stack;
                    return false; // stackoverflow
                }
                stack[++top] = num;
            } catch (...) {
                delete[] stack;
                return false;
            }
        }
    }

    if (top != 0) {
        delete[] stack;
        return false; // incorrect number of operands
    }

    result = stack[0];
    delete[] stack;
    return true;
}

}
