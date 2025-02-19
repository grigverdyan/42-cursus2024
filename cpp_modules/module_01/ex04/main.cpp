#include <iostream>
#include <fstream>
#include <string>

std::string myReplace(const std::string& line, const std::string& from, const std::string& to);

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <str1> <str2>" << std::endl;
        return 1;
    }
    std::fstream file;
    file.open(argv[1], std::fstream::in);

    if (file.fail())
    {
        std::cerr << "Error opening file " << argv[1] << std::endl;
        return 1;
    }

    std::fstream newFile;
    std::string newFileName = std::string(argv[1]) + ".replace";
    newFile.open(newFileName.c_str(), std::fstream::out);

    if (newFile.fail())
    {
        std::cerr << "Error creating file " << argv[1] << ".replace" << std::endl;
        file.close();
        return 1;
    }

    std::string line;

    while (std::getline(file, line))
    {
        newFile << myReplace(line, argv[2], argv[3]) << std::endl;
    }

    file.close();
    newFile.close();

    return 0;
}

std::string myReplace(const std::string& line, const std::string& from, const std::string& to)
{
    std::string newLine;

    size_t start = 0;
    size_t end = 0;

    while ((end = line.find(from, start)) != std::string::npos)
    {
        newLine.append(line, start, end - start);
        newLine.append(to);
        start = end + from.length();
    }

    newLine.append(line, start, line.length() - start);
    return newLine;
}