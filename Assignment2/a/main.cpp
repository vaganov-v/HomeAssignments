/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 2a
 */

#include "file_utils.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    std::string output = argv[2];

    if (fileutils::reverseBinaryFile(input, output)) {
        std::cout << "File reversed successfully" << std::endl;
        return 0;
    }
    else{
        std::cerr << "Failed to reverse file" << std::endl;
        return 1;
    }
}
