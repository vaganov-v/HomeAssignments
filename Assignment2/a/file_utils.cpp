/*
 * Ваганов Владимир Алексеевич
 * st140060@student.spbu.ru
 * Assignment 2
 */

#include "file_utils.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fileutils{

bool reverseBinaryFile(const std::string& inputPath, const std::string& outputPath)
{
    //1. check if file exists
    if (!std::filesystem::exists(inputPath)) {
        std::cerr << "Input file does not exist: " << inputPath << std::endl;
        return false;
    }

    //2. Get file size
    std::uintmax_t fileSize = std::filesystem::file_size(inputPath);
    if (fileSize == 0){
        std::cerr << "Input file is empty." << std::endl;
        return false;
    }

    //3. Allocate memory
    char* buffer = new char[fileSize];

    //4. Open the file for reading
    std::ifstream infile(inputPath, std::ios::binary);
    if (!infile) {
        std::cerr << "Cannot open input file" << std::endl;
        delete[] buffer;
        return false;
    }

    //5. Read the file
    infile.read(buffer, static_cast<std::streamsize>(fileSize));
    infile.close();

    if (infile.gcount() != static_cast<std::streamsize>(fileSize)) {
        std::cerr << "Failed to read full file" << std::endl;
        delete[] buffer;
        return false;
    }

    //6. Expand the array
    for (std::size_t i = 0; i < fileSize / 2; ++i) {
        char temp = buffer[i];
        buffer[i] = buffer[fileSize - 1 - i];
        buffer[fileSize - 1 - i] = temp;
    }

    //7.Declare outfile
    std::ofstream outfile(outputPath, std::ios::binary);
    if (!outfile) {
        std::cerr << "Cannot create output file" << outputPath << std::endl;
        delete[] buffer;
        return false;
    }
    outfile.write(buffer, static_cast<std::streamsize>(fileSize));
    outfile.close();

    //8.Release memory
    delete[] buffer;
    return true;
}

}
